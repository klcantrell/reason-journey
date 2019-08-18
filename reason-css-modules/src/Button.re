[@bs.deriving {abstract: light}]
type styles = {
  base: string,
  purple: string,
  green: string,
  small: string,
  medium: string,
  large: string,
};
[@bs.module] [@bs.val] external styles: styles = "./Button.css";

module Cx = {
  let make = classes => {
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
};

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
    className={Cx.make([|
      styles |> base,
      styles |> styleOfColor(color),
      styles |> styleOfSize(size),
    |])}>
    children
  </button>;
