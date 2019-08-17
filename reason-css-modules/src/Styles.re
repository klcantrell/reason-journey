type theme = {
  mainColor: string,
  secondaryColor: string,
};

[@bs.module "emotion"] [@bs.val] external css: string => string = "css";

let app = (theme: theme) => {
  {j|
    border: 1px solid black;
    color: $theme.mainColor);
  |j} |> css;
};
