exception NoSuchStyle;

[@bs.deriving {abstract: light}]
type styles = {
  base: Js.Nullable.t(string),
  purple: Js.Nullable.t(string),
  green: Js.Nullable.t(string),
  small: Js.Nullable.t(string),
  medium: Js.Nullable.t(string),
  large: Js.Nullable.t(string),
};

[@bs.module] [@bs.val] external styles: styles = "./Button.css";

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

type styleSource('a) =
  | CssModule(styles => Js.Nullable.t(string))
    : styleSource(styles => Js.Nullable.t(string))
  | ColorProp(color): styleSource(styles => Js.Nullable.t(string))
  | SizeProp(size): styleSource(styles => Js.Nullable.t(string));

module Cx = {
  let composeStyles = classes => {
    classes
    |> Array.fold_left(
         (acc, class_) =>
           switch (acc) {
           | "" => acc ++ class_
           | _ => acc ++ " " ++ class_
           },
         "",
       );
  };

  let unwrapNullableStyle = style =>
    switch (Js.Nullable.toOption(style)) {
    | None => raise(NoSuchStyle)
    | Some(presentStyle) => presentStyle
    };

  let extractStylesWithSource: type t. styleSource(t) => t =
    fun
    | CssModule(className) => className
    | ColorProp(color) => styleOfColor(color)
    | SizeProp(size) => styleOfSize(size);

  let extractStyle = (styleSource, styles) => {
    switch (styleSource) {
    | CssModule(className) =>
      styles
      |> extractStylesWithSource(CssModule(className))
      |> unwrapNullableStyle
    | ColorProp(color) =>
      styles
      |> extractStylesWithSource(ColorProp(color))
      |> unwrapNullableStyle
    | SizeProp(size) =>
      styles
      |> extractStylesWithSource(SizeProp(size))
      |> unwrapNullableStyle
    };
  };
};

[@react.component]
let make = (~children, ~color: color=`Purple, ~size: size=`Medium) =>
  <button
    className={Cx.composeStyles([|
      styles |> Cx.extractStyle(CssModule(base)),
      styles |> Cx.extractStyle(ColorProp(color)),
      styles |> Cx.extractStyle(SizeProp(size)),
    |])}>
    children
  </button>;
