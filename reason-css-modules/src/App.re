let str = ReasonReact.string;

[@bs.deriving {abstract: light}]
type styles = {app: string};

[@bs.module] [@bs.val] external globalStyles: 'css = "./Global.css";
[@bs.module] [@bs.val] external styles: styles = "./App.css";
[@bs.val] external alert: string => unit = "alert";

let handleClick = _event => alert("clicked!");

[@react.component]
let make = (~message) =>
  <div className={styles->app} onClick=handleClick>
    {str(message)}
    <p> {str("This should be the secondary color")} </p>
  </div>;
