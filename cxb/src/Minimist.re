type rawInput = array(string);

module type Expected = {
  type alias;
  type default;
  type output;
  let alias: Js.t(alias);
  let default: Js.t(default);
};

module Make = (Args: Expected) => {
  [@bs.deriving abstract]
  type options('a, 'b) = {
    string,
    boolean: string,
    alias: Js.t('a),
    default: Js.t('b),
    unknown: string => unit,
  };

  let makeOptions = options(~alias=Args.alias, ~default=Args.default);

  [@bs.module]
  external minimist_: (rawInput, options('a, 'b)) => Js.t(Args.output) =
    "minimist";

  let parse = (options, input) => {
    minimist_(input, options);
  };
};
