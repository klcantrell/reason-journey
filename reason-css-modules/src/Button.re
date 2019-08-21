open ButtonStyles;

type style = ButtonStyles.t;

[@bs.module] [@bs.val] external styles: style = "./Button.css";

type color = [ | `Purple | `Green];

let styleOfColor = (color: color) =>
  switch (color) {
  | `Purple => purple
  | `Green => green
  };

type size = [ | `Small | `Medium | `Large];

let styleOfSize = (size: size) =>
  switch (size) {
  | `Small => small
  | `Medium => medium
  | `Large => large
  };

[@react.component]
let make = (~children, ~color: color=`Purple, ~size: size=`Medium) =>
  <div className={styles |> Cx.extractSingleStyle(buttonContainer)}>
    <button
      className={
        styles
        |> Cx.extractStyles([base, styleOfColor(color), styleOfSize(size)])
        |> Cx.composeStyles
      }>
      children
    </button>
  </div>;
