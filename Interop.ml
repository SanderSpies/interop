module Ast = Spider_monkey_ast

let main content =
  let parse_options = Some Parser_env.({
      esproposal_class_instance_fields = true;
      esproposal_class_static_fields = true;
      esproposal_decorators = true;
      esproposal_export_star_as = true;
      types = true;
      use_strict = false;
    }) in

  let (ocaml_ast, _ ) =
    Parser_flow.program ~fail:false ~parse_options content
  in
  let (_, statements, _) = ocaml_ast 
  in 
  let fixUpperCase str =
    if (String.make 1 str.[0]) = (String.uppercase (String.make 1 str.[0])) then
      "_"  ^ str
    else
      str
  in
  let rec process_type typeAnnotation =
    Ast.Type.(match typeAnnotation with
        | _, String -> "string"
        | _, Void -> "unit"
        | _, Number -> "float"
        | _, Boolean -> "bool"
        | _, Generic {
            Generic.id = Generic.Identifier.Unqualified (id);
            _
          } -> (
            let _, { Ast.Identifier.name; _ } = id in
            match name with
            | "mixed" -> "'a" (* TODO: b c d e etc. *)
            | _ -> name

          )
        | _, Function { Function.params; returnType; rest; _ (*typeParameters*) } -> (
            let params =
              String.concat "" (List.map (fun param ->
                  let (_, {Ast.Type.Function.Param.name; optional; typeAnnotation; _}) = param
                  in
                  let (_, name) = name in
                  let prefix = if optional then (
                      "?" ^ Ast.Identifier.(name.name) ^ ":"
                    )
                    else (
                      ""
                    )
                  in
                  prefix ^ (process_type typeAnnotation) ^ " -> "
                ) params)
            in
            let restParam = match rest with (* TODO: once we figure out how to do this... *)
              | Some restParam -> "'rest array -> "
              | None -> ""
            in
            params ^ restParam ^ (process_type returnType);
          )
        | _ -> assert false (* TODO support more! *)
      )

  and hasRestParameter value =
    Ast.Type.(match value with
        | _, Function {Function.rest = Some _; _} -> true
        | _ -> false)
  and create_interop statements =
    Ast.Statement.(match statements with
        | (_, DeclareVariable { DeclareVariable.id; }) :: tail -> (
            let _, { Ast.Identifier.name; typeAnnotation; _; } = id in

            (match typeAnnotation with
             | Some (_, typeAnnotation) -> (
                 match typeAnnotation with
                 | _, Ast.Type.Object obj -> (
                     print_string ("module " ^ (String.capitalize name) ^ " = struct");
                     print_newline();
                     print_string (process_object name obj);
                     print_newline();
                     print_string ("end");
                     print_newline()

                   )
                 | _ -> (
                     print_string ("external " ^ (fixUpperCase name) ^ ": ");
                     let type_ = process_type typeAnnotation in
                     print_string type_;
                     print_string (" = \"" ^ name ^ "\" [@@bs.val];;")
                   )
               )
             | None -> assert false);
            print_newline ();
            create_interop tail
          )
        | (_, DeclareFunction { DeclareFunction.id; _; }) :: tail -> (
            let _, { Ast.Identifier.name; typeAnnotation; _ } = id in
            (match typeAnnotation with
             | Some (_, typeAnnotation) -> (
                 let type_ = process_type typeAnnotation in
                 print_string ("external " ^ (fixUpperCase name) ^ ": ");
                 print_string type_;
                 print_string (" = \"" ^ name ^ "\" [@@bs.val];;"))
             | None -> assert false);
            print_newline ();
            create_interop tail
          )
        | (_, DeclareClass { Interface.id; _; }) :: tail -> (
            let _, { Ast.Identifier.name; _ } = id in
            print_string ("module " ^ (String.capitalize name) ^ " = struct");
            print_newline();
            (* print_string (process_object name obj); *)
            print_newline();
            print_string ("end");
            print_newline();
            create_interop tail
          )
        | (_, DeclareModule _) :: tail -> create_interop tail
        | (_, Empty) :: tail -> create_interop tail
        | _ :: tail -> create_interop tail
        | [] -> ())

  and process_object moduleName (obj:Ast.Type.Object.t) =
    let {Ast.Type.Object.properties; _} = obj in
    let rec process_properties properties result =
      match properties with
      | (_, {Ast.Type.Object.Property.key; value; _}) :: tail ->  (
          match key with
          | Ast.Expression.Object.Property.Literal
              (_, { Ast.Literal.value = Ast.Literal.String name; _ })
          | Ast.Expression.Object.Property.Identifier
              (_, { Ast.Identifier.name; _ }) ->
            let splice = if hasRestParameter value then
                " [@@bs.splice]"
              else
                ""
            in
            process_properties tail (result ^ "  external " ^ (fixUpperCase name) ^ ": " ^(process_type value) ^ " = \"" ^ moduleName ^ "." ^ name ^ "\" [@@bs.val]" ^ splice ^ "\n")

          | _ -> assert false
        )
      | _ -> result
    in process_properties properties ""
  in create_interop statements
;;

let load_file f =
  let ic = open_in f in
  let n = in_channel_length ic in
  let s = Bytes.create n in
  really_input ic s 0 n;
  close_in ic;
  (s)
;;


let file_name = (Array.get Sys.argv 1) in
let contents = load_file file_name in
main contents