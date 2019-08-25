[@bs.deriving {abstract: light}]
type rule = {selectors: array(string)};

[@bs.deriving {abstract: light}]
type stylesheet = {rules: array(rule)};

[@bs.deriving {abstract: light}]
type cssAst = {stylesheet};

[@bs.module "css"] [@bs.val] external parse: string => cssAst = "parse";
