module Minimist =
  Minimist.Make({
    type output = {. path: string};
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

    let alias = {"p": "path", "h": "help"};
    let default = {"path": ".", "help": false};
    let string = [|"path"|];
    let boolean = [|"help"|];
    let unknown = err => Js.log(err);
  });

Js.log([|"--path", "dude"|] |> Minimist.parse);

let myCss = Css.parse(Knode.Fs.readFileSync(. "test.css", "utf8"));

Js.log(
  myCss
  |> Css.stylesheet
  |> Css.rules
  |> Array.map(rule => (rule |> Css.selectors)[0]),
);

let watcher = Chokidar.makeWatcher("**/*.css");
let handleChange = path => {
  Js.log({j|Detected change in $path|j});
};

watcher |> Chokidar.onChange @@ handleChange;