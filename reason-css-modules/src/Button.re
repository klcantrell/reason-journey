[@bs.deriving {abstract: light}]
type style = {
  base: Js.Nullable.t(string),
  purple: Js.Nullable.t(string),
  green: Js.Nullable.t(string),
  small: Js.Nullable.t(string),
  medium: Js.Nullable.t(string),
  large: Js.Nullable.t(string),
};

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
  <button
    className={
      styles
      |> Cx.extractStyles([base, styleOfColor(color), styleOfSize(size)])
      |> Cx.composeStyles
    }>
    children
  </button>;
