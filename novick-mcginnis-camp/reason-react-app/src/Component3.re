let str = ReasonReact.string;

[@bs.val] external alert: string => unit = "alert";

let handleClick = _event => alert("You clicked!");

[@react.component]
let make = () =>
  <div>
    <div>"Sup" -> str</div>
    <button onClick=handleClick>"YO"->str</button>
  </div>;