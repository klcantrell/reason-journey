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

Js.log({j|Listening for changes in $pathArg|j});

let watcher = Chokidar.makeWatcher("**/*.css");

let tail = array => array[Array.length(array) - 1];

let head = array => array[0];

let pathFragments = string => string |> Js.String.split("//");

let makeRuleTypes = rules => {
  rules
  |> Js.Array.map(rule =>
       rule |> Js.String.slice(~from=1, ~to_=Js.String.length(rule))
     )
  |> Js.Array.map(ruleName => {j|$ruleName: Js.Nullable.t(string)|j})
  |> Js.Array.reduce((str, currentRule) => str ++ "\n\t" ++ currentRule, "");
};

let precedingPath = path => {
  switch (path |> pathFragments) {
  | p when Js.Array.length(p) === 1 => ""
  | p =>
    p
    |> Js.Array.slice(~start=0, ~end_=Js.Array.length(p) - 1)
    |> Knode.Path.join
  };
};

let formatFilename = baseName => {
  (baseName |> Js.String.charAt(0) |> Js.String.toUpperCase)
  ++ (
    baseName
    |> Js.String.slice(~from=1, ~to_=Js.String.length(baseName))
    |> Js.String.toLowerCase
  )
  ++ "Styles.re";
};

let originalFilename = path => {
  path |> pathFragments |> tail;
};

let makeFilename = path => {
  path
  |> pathFragments
  |> tail
  |> Js.String.split(".")
  |> head
  |> formatFilename;
};

let makeContent = (ruleTypes, externalFilename) => {
  {j|// GENERATED CONTENT - PLEASE DO NOT EDIT
[@bs.deriving {abstract: light}]
type t = {$ruleTypes
};

[@bs.module] [@bs.val] external externalStyles: t = "./$externalFilename"
  |j};
};

let writeFile = (path, content) => {
  Knode.Fs.writeFileSync(. path, content, "utf8", err =>
    switch (err) {
    | exception (Js.Exn.Error(e)) =>
      let reason =
        Js.Exn.message(e)->Belt.Option.getWithDefault("unknown error");
      Js.log({j|Something went wrong: $reason|j});
    | _ => ()
    }
  );
  Js.log("File created");
};

let makeReasonBindings = (path, rules) => {
  let originalFilename = path |> originalFilename;
  let newFilename = path |> makeFilename;
  let precedingPath = path |> precedingPath;
  let ruleTypes = rules |> makeRuleTypes;
  let content = makeContent(ruleTypes, originalFilename);
  let newFilepath =
    switch (precedingPath) {
    | "" => newFilename
    | _ => precedingPath ++ "\\" ++ newFilename
    };

  Js.log({j|Creating file in $newFilename...|j});

  writeFile(Knode.Path.join([|newFilepath|]), content);
};

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
    rules |> Js.Array.length > 0 ? makeReasonBindings(path, rules) : ();
  };
};

watcher |> Chokidar.onChange @@ handleChange;
