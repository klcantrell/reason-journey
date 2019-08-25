type rawInput = array(string);

module type Config = {
  type alias;
  type default;
  type output;
  let alias: Js.t(alias);
  let default: Js.t(default);
  let string: array(string);
  let boolean: array(string);
  let unknown: string => unit;
};

module Make = (Config: Config) => {
  [@bs.deriving abstract]
  type settings('a, 'b) = {
    string: array(string),
    boolean: array(string),
    alias: Js.t('a),
    default: Js.t('b),
    unknown: string => unit,
  };

  [@bs.module]
  external minimist_: (rawInput, settings('a, 'b)) => Js.t(Config.output) =
    "minimist";

  let parse = input => {
    minimist_(
      input,
      settings(
        ~string=Config.string,
        ~boolean=Config.boolean,
        ~alias=Config.alias,
        ~default=Config.default,
        ~unknown=Config.unknown,
      ),
    );
  };
};
