type styles = {. "app": string};

[@bs.module] [@bs.val] external globalStyles: unit = "./global.css";
[@bs.module] [@bs.val] external styles: styles = "./App.css";
[@bs.val] external alert: string => unit = "alert";

let handleClick = _event => alert("clicked!");

[@react.component]
let make = (~message) =>
  <div
    className={
      styles##app;
    }
    onClick=handleClick>
    {ReasonReact.string(message)}
    <p> {ReasonReact.string("This should be blue")} </p>
  </div>;
