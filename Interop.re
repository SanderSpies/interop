let module Ast = Spider_monkey_ast;

let parse_options =
  Some Parser_env.{
         esproposal_class_instance_fields: true,
         esproposal_class_static_fields: true,
         esproposal_decorators: true,
         esproposal_export_star_as: true,
         types: true,
         use_strict: false
       };

let fixUpperCase str =>
  if (String.make 1 str.[0] == String.uppercase (String.make 1 str.[0])) {
    "_" ^ str
  } else {
    str
  };

let reservedNames = ["assert", "exception", "type"];

let fixReservedNames str =>
  if (List.exists (fun a => a == str) reservedNames) {
    "_" ^ str
  } else {
    str
  };

let hasRestParameter value =>
  Ast.Type.(
    switch value {
    | (_, Function {Function.rest: Some _, _}) => true
    | _ => false
    }
  );

let getTypeName moduleName =>
  switch moduleName {
  | "Boolean" => "bool"
  | "Number" => "float"
  | _ => "t"
  };
let isLiteral value => {
  Ast.Type.(switch value {
  | (_, StringLiteral _)
  | (_, BooleanLiteral _)
  | (_, NumberLiteral _) => true
  | _ => false
  });
};
let rec process_type typeAnnotation =>
  Ast.Type.(
    switch typeAnnotation {
    | (_, String) => "string"
    | (_, Void) => "unit"
    | (_, Number) => "float"
    | (_, Boolean) => "bool"
    | (_, Any) => "'a"
    | (_, StringLiteral {StringLiteral.value, _}) => "\"" ^ value ^ "\""
    | (_, NumberLiteral {NumberLiteral.value, _}) => "" ^ string_of_float(value) ^ ""
    | (_, BooleanLiteral {BooleanLiteral.value, _}) => "" ^ string_of_bool(value) ^ ""
    | (_, Generic {Generic.id: Generic.Identifier.Unqualified id, _}) =>
      let (_, {Ast.Identifier.name: name, _}) = id;
      switch name {
      | "mixed" => "'a" /* TODO: b c d e etc. */
      | "Boolean" => "bool"
      | "Number" => "float"
      | "Function" => "(unit => unit)"
      | _ => name
      }
    | (
        _,
        Function {
          Function.params: params,
          returnType,
          rest,
          _ /*typeParameters*/
        }
      ) =>
      process_function params rest ^ process_type returnType
    | _ => "TODO" /* TODO support more! */
    }
  )
and process_function params rest => {
  let params =
    String.concat
      ""
      (
        List.map
          (
            fun param => {
              let (_, {Ast.Type.Function.Param.name: name, optional, typeAnnotation, _}) = param;
              let (_, name) = name;
              let (prefix, postfix) =
                if optional {
                  (Ast.Identifier.(name.name) ^ "::(option ", ")")
                } else {
                  ("", "")
                };
              prefix ^ process_type typeAnnotation ^ postfix ^ " => "
            }
          )
          params
      );
  let restParam =
    switch rest {
    | Some restParam => "array 'rest => "
    | None => ""
    };
  let fix =
    if (params == "" && restParam == "") {
      "unit => "
    } else {
      ""
    };
  fix ^ params ^ restParam
}
and findClass statements type_ => {
  Ast.Statement.(
    switch statements {
    | [(_, DeclareClass {Interface.id: id, body, _}), ...tail] => {
        let (_, {Ast.Identifier.name: name, _}) = id;
        if (name == type_) {
          Some body
        } else {
          findClass tail type_
        }
      }
    | [hd, ...tail] => findClass tail type_
    | [] => None
    }
  )
}
and create_interop statements allStatements =>
  Ast.Statement.(
    switch statements {
    | [(_, DeclareVariable {DeclareVariable.id: id}), ...tail] =>
      let (_, {Ast.Identifier.name: name, typeAnnotation, _}) = id;
      switch typeAnnotation {
      | Some (_, typeAnnotation) =>
        switch typeAnnotation {
        | (_, Ast.Type.Object obj) =>
          print_string ("let module " ^ String.capitalize name ^ " = {");
          print_newline ();
          print_string (process_object name obj);
          print_string "};";
        | _ =>

          let type_ = process_type typeAnnotation;
          let foundClass = findClass allStatements type_;
          switch foundClass {
            | Some (_, obj) => {
              print_string ("let module " ^ String.capitalize name ^ "Instance = {");
              print_newline ();
              print_string(process_object name obj);
              print_string "};";
              }
            | None => print_string ("external " ^ fixUpperCase name ^ ": " ^ type_ ^ " = \"" ^ name ^ "\" [@@bs.val];")
          };
        }
      | None => assert false
      };
      print_newline ();
      create_interop tail  allStatements
    | [(_, DeclareFunction {DeclareFunction.id: id, _}), ...tail] =>
      let (_, {Ast.Identifier.name: name, typeAnnotation, _}) = id;
      switch typeAnnotation {
      | Some (_, typeAnnotation) =>
        let type_ = process_type typeAnnotation;
        print_string ("external " ^ fixUpperCase name ^ ": ");
        print_string type_;
        print_string (" = \"" ^ name ^ "\" [@@bs.val];")
      | None => assert false
      };
      print_newline ();
      create_interop tail  allStatements
    | [(_, DeclareClass {Interface.id: id, body, _}), ...tail] =>
      let (_, {Ast.Identifier.name: name, _}) = id;
      let (_, obj) = body;
      print_string ("let module " ^ String.capitalize name ^ " = {\n  type t;");
      print_newline ();
      print_string (process_class name obj);
      print_string "};";
      print_newline ();
      create_interop tail  allStatements
    | [(_, DeclareModule _), ...tail] => create_interop tail  allStatements
    | [(_, Empty), ...tail] => create_interop tail  allStatements
    | [(_, TypeAlias a), ...tail] =>
        print_string "type TODO;";
        print_newline();
        create_interop tail  allStatements
    | [_, ...tail] => create_interop tail  allStatements
    | [] => ()
    }
  )
and process_class moduleName (obj: Ast.Type.Object.t) => {
  let {Ast.Type.Object.properties: properties, callProperties, _} = obj;
  let rec process_properties properties result =>
    switch properties {
    | [(_, {Ast.Type.Object.Property.key: key, value, static, _method,_}), ...tail] =>
      switch key {
      | Ast.Expression.Object.Property.Literal _ {Ast.Literal.value: Ast.Literal.String name, _}
        [@implicit_arity]
      | Ast.Expression.Object.Property.Identifier _ {Ast.Identifier.name: name, _}
        [@implicit_arity] =>
        let splice =
          if (hasRestParameter value) {
            " [@@bs.splice]"
          } else {
            ""
          };
        let (t, bsPPX) =
          if static {
            ("", "[@@bs.val]")
          }
          else if (_method) {
            let a = getTypeName moduleName;
            (a ^ " => ", "[@@bs.send]")
          }
          else {
            ("", "[@@bs.get]");
          };
        process_properties
          tail
          (
            if (isLiteral value) {
              result ^ "  let " ^ fixReservedNames (fixUpperCase name) ^ " = " ^ process_type value ^ ";\n";
            }
            else {
              result ^ "  external " ^ fixReservedNames (fixUpperCase name) ^ ": " ^ t ^ process_type value ^ " = \"\" " ^ bsPPX ^ splice ^ ";\n";
            }
          )
      | _ => assert false
      }
    | _ => result
    }
  and process_call_properties moduleName properties result hasCreateFn =>
    Ast.Type.(
      switch properties {
      | [(_, {Ast.Type.Object.CallProperty.value: value, _}), ...tail] =>
        let (_, {Function.params: params, returnType, rest, _}) = value;
        let a = getTypeName moduleName;
        process_call_properties
          moduleName
          tail
          (
            result ^
            "  external create:" ^
            (process_function params rest) ^ (process_type returnType) ^ " = \"" ^ moduleName ^ "\" [@@bs.new]; \n"
          )
          true
      | [] =>  if (hasCreateFn === false) {
          result ^ "  external create: unit => t = \"" ^ moduleName ^ "\" [@@bs.new]; \n"
        }
        else {
          result
        }
      }
    );
  process_call_properties moduleName callProperties "" false ^ process_properties properties ""
}
and process_object moduleName (obj: Ast.Type.Object.t) => {
  let {Ast.Type.Object.properties: properties, _} = obj;
  let rec process_properties properties result =>
    switch properties {
    | [(_, {Ast.Type.Object.Property.key: key, value, static, _method, _}), ...tail] =>
      switch key {
      | Ast.Expression.Object.Property.Literal _ {Ast.Literal.value: Ast.Literal.String name, _}
        [@implicit_arity]
      | Ast.Expression.Object.Property.Identifier _ {Ast.Identifier.name: name, _}
        [@implicit_arity] =>
        let splice =
          if (hasRestParameter value) {
            " [@@bs.splice]"
          } else {
            ""
          };
          let (t, bsPPX) =
            if static {
              ("", "[@@bs.val]")
            }
            else if (_method) {
              let a = getTypeName moduleName;
              (a ^ " => ", "[@@bs.send]")
            }
            else {
              ("", "[@@bs.val]");
            };
        process_properties
          tail
          (
            if (isLiteral value) {
              result ^ "  let " ^ fixReservedNames (fixUpperCase name) ^ " = " ^ process_type value ^ ";\n";
            }

            else {
              result ^
              "  external " ^
              fixReservedNames (fixUpperCase name) ^
              ": " ^
              process_type value ^
              " = \"" ^ moduleName ^ "." ^ name ^ "\" " ^ bsPPX ^ splice ^ ";\n"
            }
          )
      | _ => assert false
      }
    | _ => result
    };
  process_properties properties ""
};

let main content => {
  let (ocaml_ast, _) = Parser_flow.program fail::false parse_options::parse_options content;
  let (_, statements, _) = ocaml_ast;
  create_interop statements statements
};

let load_file f => {
  let ic = open_in f;
  let n = in_channel_length ic;
  let s = Bytes.create n;
  really_input ic s 0 n;
  close_in ic;
  s
};


let file_name = Sys.argv.(1);
let contents = load_file file_name;
main contents
