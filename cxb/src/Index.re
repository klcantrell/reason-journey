module Minimist =
  Minimist.Make({
    type output = {
      .
      path: array(string),
      help: bool,
    };
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
    let unknown = unknownArg => {
      Js.log(
        {j|Sorry, $unknownArg is an unrecognized argument! Please try again.|j},
      );
      Knode.Process.exit(0);
    };
  });

let args =
  Minimist.parse(
    Knode.Process.argv
    |> Js.Array.slice(~start=2, ~end_=Knode.Process.argv |> Array.length),
  );

args##help
  ? {
    Js.log(
      {j|
      Use the --path (alias -p) argument to specify a path to watch your css files

      Example:
      cxb --path styles

      The above exmple will watch the styles directory of your project|j},
    );
    Knode.Process.exit(0);
  }
  : ();

let pathArg = args##path |> Knode.Path.resolve;

pathArg |> Knode.Fs.existsSync
  ? ()
  : {
    Js.log({j|Sorry, the path $pathArg does not exist! Please try again.|j});
  };

Knode.Process.chdir(pathArg);

let watcher = Chokidar.makeWatcher("**/*.css");
let handleChange = path => {
  Js.log({j|Detected change in $path|j});
  let changedCss =
    Knode.Fs.readFileSync(. Knode.Path.resolve([|path|]), "utf8");
  switch (changedCss |> Css.parse) {
  | exception (Js.Exn.Error(e)) =>
    let reason =
      Js.Exn.message(e)->Belt.Option.getWithDefault("unknown error");
    Js.log({j|Something went wrong parsing css: $reason in $path|j});
  | ast =>
    let rules =
      ast
      |> Css.stylesheet
      |> Css.rules
      |> Array.map(rule => (rule |> Css.selectors)[0]);
    Js.log(rules);
  };
};

watcher |> Chokidar.onChange @@ handleChange;
