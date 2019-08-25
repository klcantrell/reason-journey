module Minimist =
  Minimist.Make({
    type alias = {
      .
      p: string,
      h: string,
    };
    type default = {
      .
      path: string,
      help: bool,
    };
    type output = {. path: string};
    let alias = {"p": "path", "h": "help"};
    let default = {"path": ".", "help": false};
  });

let options =
  Minimist.(
    makeOptions(~string="path", ~boolean="help", ~unknown=err => Js.log(err))
  );

Js.log([|"--path", "dude"|] |> Minimist.parse(options));

let myCss = Css.parse(Knode.Fs.readFileSync(. "test.css", "utf8"));

Js.log(
  myCss
  |> Css.stylesheet
  |> Css.rules
  |> Array.map(rule => (rule |> Css.selectors)[0]),
);
