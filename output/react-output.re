let module React$Component = {
  type t;
  external create: unit => t = "React$Component" [@@bs.new]; 
  external defaultProps: $Abstract = "" [@@bs.val];
  external props: Props = "" [@@bs.get];
  external state: $Abstract = "" [@@bs.get];
  external setState: t => $Shape => callback::(option unit => unit) => unit = "" [@@bs.send];
  external forceUpdate: t => callback::(option unit => unit) => unit = "" [@@bs.send];
  external render: t => unit => TODO = "" [@@bs.send];
  external componentWillMount: t => unit => unit = "" [@@bs.send];
  external componentDidMount: t => component::(option 'a) => unit = "" [@@bs.send];
  external componentWillReceiveProps: t => Props => nextContext::(option 'a) => unit = "" [@@bs.send];
  external shouldComponentUpdate: t => Props => State => 'a => bool = "" [@@bs.send];
  external componentWillUpdate: t => Props => State => 'a => unit = "" [@@bs.send];
  external componentDidUpdate: t => Props => State => 'a => 'a => unit = "" [@@bs.send];
  external componentWillUnmount: t => unit => unit = "" [@@bs.send];
  external refs: 'a = "" [@@bs.get];
  external context: 'a = "" [@@bs.get];
  external getChildContext: t => unit => 'a = "" [@@bs.send];
  external displayName: string = "" [@@bs.val];
  external childContextTypes: 'a = "" [@@bs.val];
  external contextTypes: 'a = "" [@@bs.val];
  external propTypes: $Subtype = "" [@@bs.val];
};
let module React$PureComponent = {
  type t;
  external create: unit => t = "React$PureComponent" [@@bs.new]; 
  external defaultProps: $Abstract = "" [@@bs.val];
  external props: Props = "" [@@bs.get];
  external state: $Abstract = "" [@@bs.get];
};
let module LegacyReactComponent = {
  type t;
  external create: unit => t = "LegacyReactComponent" [@@bs.new]; 
  external getDefaultProps: t => unit => DefaultProps = "" [@@bs.send];
  external getInitialState: t => unit => State = "" [@@bs.send];
  external replaceState: t => State => callback::(option unit => unit) => unit = "" [@@bs.send];
  external isMounted: t => unit => bool = "" [@@bs.send];
  external defaultProps: DefaultProps = "" [@@bs.val];
  external props: Props = "" [@@bs.get];
  external state: State = "" [@@bs.get];
  external propTypes: $Subtype = "" [@@bs.val];
  external contextTypes: 'a = "" [@@bs.val];
  external childContextTypes: 'a = "" [@@bs.val];
  external displayName: string = "" [@@bs.val];
};
type TODO;
type TODO;
type TODO;
type TODO;
let module React$Element = {
  type t;
  external create: unit => t = "React$Element" [@@bs.new]; 
  external _type: ReactClass = "" [@@bs.get];
  external props: $PropsOf = "" [@@bs.get];
  external key: TODO = "" [@@bs.get];
  external ref: 'a = "" [@@bs.get];
};
type TODO;
type TODO;
type TODO;
let module SyntheticEvent = {
  type t;
  external create: unit => t = "SyntheticEvent" [@@bs.new]; 
  external bubbles: bool = "" [@@bs.get];
  external cancelable: bool = "" [@@bs.get];
  external currentTarget: EventTarget = "" [@@bs.get];
  external defaultPrevented: bool = "" [@@bs.get];
  external eventPhase: float = "" [@@bs.get];
  external isDefaultPrevented: t => unit => bool = "" [@@bs.send];
  external isPropagationStopped: t => unit => bool = "" [@@bs.send];
  external isTrusted: bool = "" [@@bs.get];
  external nativeEvent: Event = "" [@@bs.get];
  external preventDefault: t => unit => unit = "" [@@bs.send];
  external stopPropagation: t => unit => unit = "" [@@bs.send];
  external target: EventTarget = "" [@@bs.get];
  external timeStamp: float = "" [@@bs.get];
  external _type: string = "" [@@bs.get];
  external persist: t => unit => unit = "" [@@bs.send];
};
let module SyntheticClipboardEvent = {
  type t;
  external create: unit => t = "SyntheticClipboardEvent" [@@bs.new]; 
  external clipboardData: 'a = "" [@@bs.get];
};
let module SyntheticCompositionEvent = {
  type t;
  external create: unit => t = "SyntheticCompositionEvent" [@@bs.new]; 
  external data: 'a = "" [@@bs.get];
};
let module SyntheticInputEvent = {
  type t;
  external create: unit => t = "SyntheticInputEvent" [@@bs.new]; 
  external data: 'a = "" [@@bs.get];
};
let module SyntheticUIEvent = {
  type t;
  external create: unit => t = "SyntheticUIEvent" [@@bs.new]; 
  external detail: float = "" [@@bs.get];
  external view: 'a = "" [@@bs.get];
};
let module SyntheticFocusEvent = {
  type t;
  external create: unit => t = "SyntheticFocusEvent" [@@bs.new]; 
  external relatedTarget: EventTarget = "" [@@bs.get];
};
let module SyntheticKeyboardEvent = {
  type t;
  external create: unit => t = "SyntheticKeyboardEvent" [@@bs.new]; 
  external altKey: bool = "" [@@bs.get];
  external charCode: float = "" [@@bs.get];
  external ctrlKey: bool = "" [@@bs.get];
  external getModifierState: 'a = "" [@@bs.get];
  external key: string = "" [@@bs.get];
  external keyCode: float = "" [@@bs.get];
  external locale: string = "" [@@bs.get];
  external location: float = "" [@@bs.get];
  external metaKey: bool = "" [@@bs.get];
  external repeat: bool = "" [@@bs.get];
  external shiftKey: bool = "" [@@bs.get];
  external which: float = "" [@@bs.get];
};
let module SyntheticMouseEvent = {
  type t;
  external create: unit => t = "SyntheticMouseEvent" [@@bs.new]; 
  external altKey: bool = "" [@@bs.get];
  external button: float = "" [@@bs.get];
  external buttons: float = "" [@@bs.get];
  external clientX: float = "" [@@bs.get];
  external clientY: float = "" [@@bs.get];
  external ctrlKey: bool = "" [@@bs.get];
  external getModifierState: 'a = "" [@@bs.get];
  external metaKey: bool = "" [@@bs.get];
  external pageX: float = "" [@@bs.get];
  external pageY: float = "" [@@bs.get];
  external relatedTarget: EventTarget = "" [@@bs.get];
  external screenX: float = "" [@@bs.get];
  external screenY: float = "" [@@bs.get];
  external shiftKey: bool = "" [@@bs.get];
};
let module SyntheticDragEvent = {
  type t;
  external create: unit => t = "SyntheticDragEvent" [@@bs.new]; 
  external dataTransfer: 'a = "" [@@bs.get];
};
let module SyntheticWheelEvent = {
  type t;
  external create: unit => t = "SyntheticWheelEvent" [@@bs.new]; 
  external deltaMode: float = "" [@@bs.get];
  external deltaX: float = "" [@@bs.get];
  external deltaY: float = "" [@@bs.get];
  external deltaZ: float = "" [@@bs.get];
};
let module SyntheticTouchEvent = {
  type t;
  external create: unit => t = "SyntheticTouchEvent" [@@bs.new]; 
  external altKey: bool = "" [@@bs.get];
  external changedTouches: 'a = "" [@@bs.get];
  external ctrlKey: bool = "" [@@bs.get];
  external getModifierState: 'a = "" [@@bs.get];
  external metaKey: bool = "" [@@bs.get];
  external shiftKey: bool = "" [@@bs.get];
  external targetTouches: 'a = "" [@@bs.get];
  external touches: 'a = "" [@@bs.get];
};
type TODO;
