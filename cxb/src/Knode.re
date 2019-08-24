module Fs = {
  [@bs.module "fs"]
  external existsSync: (~path: string) => bool = "existsSync";

  [@bs.module "fs"]
  external readFileSync: (~path: string, ~encoding: string) => string =
    "readFileSync";

  [@bs.module "fs"]
  external writeFileSync:
    (
      ~path: string,
      ~content: string,
      ~encoding: string,
      ~errorHandler: string => unit
    ) =>
    string =
    "writeFileSync";
};

module Path = {
  [@bs.module "path"] [@bs.variadic]
  external resolve: array(string) => string = "resolve";

  [@bs.module "path"] [@bs.variadic]
  external join: array(string) => string = "join";
};

module Process = {
  [@bs.scope "process"] [@bs.val] external argv: string = "argv";
  [@bs.scope "process"] [@bs.val] external exit: int => unit = "exit";
  [@bs.scope "process"] [@bs.val] external chdir: string => unit = "chdir";
};
