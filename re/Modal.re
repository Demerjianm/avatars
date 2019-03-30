[%bs.raw {|require('./Modal.css')|}];
let component = ReasonReact.statelessComponent("Modal");

let make = (~visible, ~onToggle, _children) => {
  ...component,
  render: _self => switch(visible) {
    | false => ReasonReact.null
    | _ =>
    <>
    <div onClick=(_ => onToggle()) className="Modal-overlay" />
    <div className="Modal-container">
      <button onClick=(_ => onToggle()) className="Modal-close">
       <img width="18" height="18" className="Modal-close--icon" src="/images/close.svg" />
      </button>
      <h3 className="Modal-title"> {ReasonReact.string("Enjoy your avatar!")} </h3>
   
     
    </div>
    </>
  }
};

let default = ReasonReact.wrapReasonForJs(~component, jsProps => make(
    ~visible=jsProps##visible,
    ~onToggle=jsProps##onToggle,
    [||]));
