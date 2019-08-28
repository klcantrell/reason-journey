// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("css");
var Path = require("path");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Chokidar = require("chokidar");
var Knode$Cxb = require("./Knode.bs.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Chokidar$Cxb = require("./Chokidar.bs.js");
var Minimist$Cxb = require("./Minimist.bs.js");
var Caml_splice_call = require("bs-platform/lib/js/caml_splice_call.js");
var Caml_js_exceptions = require("bs-platform/lib/js/caml_js_exceptions.js");

var alias = {
  p: "path",
  h: "help"
};

var $$default = {
  path: ".",
  help: false
};

var string = /* array */["path"];

var $$boolean = /* array */["help"];

function unknown(unknownArg) {
  console.log("\nSorry, " + (String(unknownArg) + " is an unrecognized argument! Please try again.\n"));
  process.exit(0);
  return /* () */0;
}

var Minimist = Minimist$Cxb.Make(/* module */[
      /* alias */alias,
      /* default */$$default,
      /* string */string,
      /* boolean */$$boolean,
      /* unknown */unknown
    ]);

var args = Curry._1(Minimist[/* parse */0], process.argv.slice(2, process.argv.length));

var match = args.help;

if (match) {
  console.log("\n      Use the --path (alias -p) argument to specify a path to watch your css files\n\n      Example:\n      cxb --path styles\n\n      The above exmple will watch the styles directory of your project\n      ");
  process.exit(0);
}

var pathArg = Path.resolve(args.path);

var match$1 = Knode$Cxb.Fs[/* existsSync */0](pathArg);

if (!match$1) {
  console.log("\nSorry, the path " + (String(pathArg) + " does not exist! Please try again.\n"));
}

process.chdir(pathArg);

console.log("\nListening for changes in " + (String(pathArg) + "\n"));

var watcher = Chokidar.watch("**/*.css");

function tail(array) {
  return Caml_array.caml_array_get(array, array.length - 1 | 0);
}

function head(array) {
  return Caml_array.caml_array_get(array, 0);
}

function pathFragments(string) {
  return string.split("//");
}

function makeRuleTypes(rules) {
  return rules.map((function (rule) {
                    return rule.slice(1, rule.length);
                  })).map((function (ruleName) {
                  return "" + (String(ruleName) + ": Js.Nullable.t(string)");
                })).reduce((function (str, currentRule) {
                return str + ("\n\t" + currentRule);
              }), "");
}

function precedingPath(path) {
  var p = path.split("//");
  if (p.length === 1) {
    return "";
  } else {
    return Caml_splice_call.spliceApply(Path.join, [p.slice(0, p.length - 1 | 0)]);
  }
}

function formatFilename(baseName) {
  return baseName.charAt(0).toUpperCase() + (baseName.slice(1, baseName.length).toLowerCase() + "Styles.re");
}

function originalFilename(path) {
  return tail(path.split("//"));
}

function makeFilename(path) {
  return formatFilename(Caml_array.caml_array_get(tail(path.split("//")).split("."), 0));
}

function makeContent(ruleTypes, externalFilename) {
  return "// GENERATED CONTENT - PLEASE DO NOT EDIT\n[@bs.deriving {abstract: light}]\ntype t = {" + (String(ruleTypes) + ("\n};\n\n[@bs.module] [@bs.val] external externalStyles: t = \"./" + (String(externalFilename) + "\"\n  ")));
}

function writeFile(path, content) {
  Knode$Cxb.Fs[/* writeFileSync */2](path, content, "utf8", (function (err) {
          try {
            return /* () */0;
          }
          catch (raw_exn){
            var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
            if (exn[0] === Js_exn.$$Error) {
              var reason = Belt_Option.getWithDefault(exn[1].message, "unknown error");
              console.log("\nSomething went wrong: " + (String(reason) + "\n"));
              return /* () */0;
            } else {
              throw exn;
            }
          }
        }));
  console.log("File created\n");
  return /* () */0;
}

function makeReasonBindings(path, rules) {
  var originalFilename = tail(path.split("//"));
  var newFilename = makeFilename(path);
  var precedingPath$1 = precedingPath(path);
  var ruleTypes = makeRuleTypes(rules);
  var content = makeContent(ruleTypes, originalFilename);
  var newFilepath = precedingPath$1 === "" ? newFilename : precedingPath$1 + ("\\" + newFilename);
  console.log("Creating file in " + (String(newFilename) + "..."));
  return writeFile(Path.join(newFilepath), content);
}

function handleChange(path) {
  console.log("Detected change in " + (String(path) + ""));
  var changedCss = Knode$Cxb.Fs[/* readFileSync */1](Path.resolve(path), "utf8");
  var exit = 0;
  var ast;
  try {
    ast = Css.parse(changedCss);
    exit = 1;
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn[0] === Js_exn.$$Error) {
      var reason = Belt_Option.getWithDefault(exn[1].message, "unknown error");
      console.log("Something went wrong parsing css: " + (String(reason) + (" in " + (String(path) + ""))));
      return /* () */0;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    var rules = $$Array.map((function (rule) {
            return Caml_array.caml_array_get(rule.selectors, 0);
          }), ast.stylesheet.rules);
    var match = rules.length > 0;
    if (match) {
      return makeReasonBindings(path, rules);
    } else {
      return /* () */0;
    }
  }
  
}

Chokidar$Cxb.onChange(handleChange, watcher);

exports.Minimist = Minimist;
exports.args = args;
exports.pathArg = pathArg;
exports.watcher = watcher;
exports.tail = tail;
exports.head = head;
exports.pathFragments = pathFragments;
exports.makeRuleTypes = makeRuleTypes;
exports.precedingPath = precedingPath;
exports.formatFilename = formatFilename;
exports.originalFilename = originalFilename;
exports.makeFilename = makeFilename;
exports.makeContent = makeContent;
exports.writeFile = writeFile;
exports.makeReasonBindings = makeReasonBindings;
exports.handleChange = handleChange;
/* Minimist Not a pure module */
