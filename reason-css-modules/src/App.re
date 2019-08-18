let str = ReasonReact.string;

[@bs.val] external alert: string => unit = "alert";

[@bs.deriving {abstract: light}]
type styles = {app: string};
[@bs.module] [@bs.val] external styles: styles = "./App.css";

let handleClick = _event => alert("clicked!");

[@react.component]
let make = (~message) =>
  <div className={styles |> app} onClick=handleClick>
    {str(message)}
    <p> {str("This should be the secondary color")} </p>
    <Button color=`Green size=`Large> {str("Sup")} </Button>
  </div>;
