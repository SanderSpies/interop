let module React$Component = {
  type t;
  external defaultProps: $Abstract = "" [@@bs.val];
  external props: t => Props = "" [@@bs.send];
  external state: t => $Abstract = "" [@@bs.send];
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
  external refs: t => 'a = "" [@@bs.send];
  external context: t => 'a = "" [@@bs.send];
  external getChildContext: t => unit => 'a = "" [@@bs.send];
  external displayName: string = "" [@@bs.val];
  external childContextTypes: 'a = "" [@@bs.val];
  external contextTypes: 'a = "" [@@bs.val];
  external propTypes: $Subtype = "" [@@bs.val];
};
let module React$PureComponent = {
  type t;
  external defaultProps: $Abstract = "" [@@bs.val];
  external props: t => Props = "" [@@bs.send];
  external state: t => $Abstract = "" [@@bs.send];
};
let module LegacyReactComponent = {
  type t;
  external getDefaultProps: t => unit => DefaultProps = "" [@@bs.send];
  external getInitialState: t => unit => State = "" [@@bs.send];
  external replaceState: t => State => callback::(option unit => unit) => unit = "" [@@bs.send];
  external isMounted: t => unit => bool = "" [@@bs.send];
  external defaultProps: DefaultProps = "" [@@bs.val];
  external props: t => Props = "" [@@bs.send];
  external state: t => State = "" [@@bs.send];
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
  external type: t => ReactClass = "" [@@bs.send];
  external props: t => $PropsOf = "" [@@bs.send];
  external key: t => TODO = "" [@@bs.send];
  external ref: t => 'a = "" [@@bs.send];
};
type TODO;
type TODO;
type TODO;
let module SyntheticEvent = {
  type t;
  external bubbles: t => bool = "" [@@bs.send];
  external cancelable: t => bool = "" [@@bs.send];
  external currentTarget: t => EventTarget = "" [@@bs.send];
  external defaultPrevented: t => bool = "" [@@bs.send];
  external eventPhase: t => float = "" [@@bs.send];
  external isDefaultPrevented: t => unit => bool = "" [@@bs.send];
  external isPropagationStopped: t => unit => bool = "" [@@bs.send];
  external isTrusted: t => bool = "" [@@bs.send];
  external nativeEvent: t => Event = "" [@@bs.send];
  external preventDefault: t => unit => unit = "" [@@bs.send];
  external stopPropagation: t => unit => unit = "" [@@bs.send];
  external target: t => EventTarget = "" [@@bs.send];
  external timeStamp: t => float = "" [@@bs.send];
  external type: t => string = "" [@@bs.send];
  external persist: t => unit => unit = "" [@@bs.send];
};
let module SyntheticClipboardEvent = {
  type t;
  external clipboardData: t => 'a = "" [@@bs.send];
};
let module SyntheticCompositionEvent = {
  type t;
  external data: t => 'a = "" [@@bs.send];
};
let module SyntheticInputEvent = {
  type t;
  external data: t => 'a = "" [@@bs.send];
};
let module SyntheticUIEvent = {
  type t;
  external detail: t => float = "" [@@bs.send];
  external view: t => 'a = "" [@@bs.send];
};
let module SyntheticFocusEvent = {
  type t;
  external relatedTarget: t => EventTarget = "" [@@bs.send];
};
let module SyntheticKeyboardEvent = {
  type t;
  external altKey: t => bool = "" [@@bs.send];
  external charCode: t => float = "" [@@bs.send];
  external ctrlKey: t => bool = "" [@@bs.send];
  external getModifierState: t => 'a = "" [@@bs.send];
  external key: t => string = "" [@@bs.send];
  external keyCode: t => float = "" [@@bs.send];
  external locale: t => string = "" [@@bs.send];
  external location: t => float = "" [@@bs.send];
  external metaKey: t => bool = "" [@@bs.send];
  external repeat: t => bool = "" [@@bs.send];
  external shiftKey: t => bool = "" [@@bs.send];
  external which: t => float = "" [@@bs.send];
};
let module SyntheticMouseEvent = {
  type t;
  external altKey: t => bool = "" [@@bs.send];
  external button: t => float = "" [@@bs.send];
  external buttons: t => float = "" [@@bs.send];
  external clientX: t => float = "" [@@bs.send];
  external clientY: t => float = "" [@@bs.send];
  external ctrlKey: t => bool = "" [@@bs.send];
  external getModifierState: t => 'a = "" [@@bs.send];
  external metaKey: t => bool = "" [@@bs.send];
  external pageX: t => float = "" [@@bs.send];
  external pageY: t => float = "" [@@bs.send];
  external relatedTarget: t => EventTarget = "" [@@bs.send];
  external screenX: t => float = "" [@@bs.send];
  external screenY: t => float = "" [@@bs.send];
  external shiftKey: t => bool = "" [@@bs.send];
};
let module SyntheticDragEvent = {
  type t;
  external dataTransfer: t => 'a = "" [@@bs.send];
};
let module SyntheticWheelEvent = {
  type t;
  external deltaMode: t => float = "" [@@bs.send];
  external deltaX: t => float = "" [@@bs.send];
  external deltaY: t => float = "" [@@bs.send];
  external deltaZ: t => float = "" [@@bs.send];
};
let module SyntheticTouchEvent = {
  type t;
  external altKey: t => bool = "" [@@bs.send];
  external changedTouches: t => 'a = "" [@@bs.send];
  external ctrlKey: t => bool = "" [@@bs.send];
  external getModifierState: t => 'a = "" [@@bs.send];
  external metaKey: t => bool = "" [@@bs.send];
  external shiftKey: t => bool = "" [@@bs.send];
  external targetTouches: t => 'a = "" [@@bs.send];
  external touches: t => 'a = "" [@@bs.send];
};
type TODO;
