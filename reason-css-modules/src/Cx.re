exception NoSuchStyle;

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

let extractNullableStyle = style => {
  switch (Js.Nullable.toOption(style)) {
  | None => raise(NoSuchStyle)
  | Some(presentStyle) => presentStyle
  };
};

let extractStyles = (styleGetters, styles) =>
  styleGetters
  |> List.map(styleGetter => styles |> styleGetter |> extractNullableStyle)
  |> Array.of_list;
