// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Express = require("bs-express/src/Express.js");
var Process = require("process");
var Pg$BasicBsExpress = require("./Pg.bs.js");
var Caml_js_exceptions = require("bs-platform/lib/js/caml_js_exceptions.js");

var app = Express.express(/* () */0);

var connectionString = "postgresql://postgres:[password]@localhost:5432/ig_clone";

var client = Pg$BasicBsExpress.makeClient(connectionString);

Express.App[/* get */4](app, "/", Express.PromiseMiddleware[/* from */0]((function (param, param$1, res) {
            var myPromise = new Promise((function (resolve, reject) {
                    return resolve("sup, my dude");
                  }));
            return myPromise.then((function (value) {
                          return Promise.resolve(Express.$$Response[/* sendString */2](value, res));
                        }));
          })));

Express.App[/* get */4](app, "/error-test", Express.Middleware[/* from */5]((function (param, param$1) {
            try {
              return Js_exn.raiseError("YIKES");
            }
            catch (raw_exn){
              var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
              if (exn[0] === Js_exn.$$Error) {
                var match = exn[1].stack;
                if (match !== undefined) {
                  var partial_arg = "Error: " + (String(match) + "");
                  var partial_arg$1 = Express.$$Response[/* sendString */2];
                  return (function (param) {
                      return partial_arg$1(partial_arg, param);
                    });
                } else {
                  var partial_arg$2 = Express.$$Response[/* sendString */2];
                  return (function (param) {
                      return partial_arg$2("An unknown error occurred", param);
                    });
                }
              } else {
                throw exn;
              }
            }
          })));

function onListen(e) {
  var exit = 0;
  var val;
  try {
    val = e;
    exit = 1;
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn[0] === Js_exn.$$Error) {
      console.log(exn[1]);
      Process.exit(1);
      return /* () */0;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    console.log("Listening at http://127.0.0.1:3000");
    return /* () */0;
  }
  
}

Express.App[/* listen */21](app, 3000, onListen, /* () */0);

exports.app = app;
exports.connectionString = connectionString;
exports.client = client;
exports.onListen = onListen;
/* app Not a pure module */
