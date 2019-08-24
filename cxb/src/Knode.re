module Fs = {
  type path = string;
  type encoding = string;
  type content = string;
  type errorHandler = string => unit;

  [@bs.module "fs"] external existsSync_: string => bool = "existsSync";

  let existsSync =
    (. path: path) => {
      existsSync_(path);
    };

  [@bs.module "fs"]
  external readFileSync_: (string, string) => string = "readFileSync";

  let readFileSync =
    (. path: path, encoding: encoding) => {
      readFileSync_(path, encoding);
    };

  [@bs.module "fs"]
  external writeFileSync_: (string, string, string, string => unit) => unit =
    "writeFileSync";

  let writeFileSync =
    (.
      path: path,
      content: content,
      encoding: encoding,
      errorHandler: errorHandler,
    ) => {
      writeFileSync_(path, content, encoding, errorHandler);
    };
};

module Path = {
  type pathFragment = string;

  [@bs.module "path"] [@bs.variadic]
  external resolve: array(pathFragment) => string = "resolve";

  [@bs.module "path"] [@bs.variadic]
  external join: array(pathFragment) => string = "join";
};

module Process = {
  type exitCode = int;
  type path = string;

  [@bs.scope "process"] [@bs.val] external argv: string = "argv";
  [@bs.scope "process"] [@bs.val] external exit: exitCode => unit = "exit";
  [@bs.scope "process"] [@bs.val] external chdir: path => unit = "chdir";
};
