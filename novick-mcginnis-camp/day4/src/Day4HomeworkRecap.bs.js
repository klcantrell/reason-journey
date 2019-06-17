// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE
'use strict';

var Drawing = require("Drawing");

function myFunc(name) {
  console.log(name);
  return /* () */0;
}

function myOtherFunc(name) {
  console.log(name);
  return /* () */0;
}

function isServerCode(code) {
  return (code / 100 | 0) === 5;
}

function isClientCode(code) {
  return (code / 100 | 0) === 5;
}

function response(param) {
  if (typeof param === "number") {
    return "Loading";
  } else if (param.tag) {
    var response$1 = param[0];
    if (response$1[/* name */0] === "Vladimir Novick") {
      return "Howdy Vladimir";
    } else {
      return response$1[/* name */0];
    }
  } else {
    var code = param[1];
    var message = param[0];
    var exit = 0;
    var switcher = code - 494 | 0;
    if (switcher > 5 || switcher < 0) {
      if (switcher !== -50) {
        exit = 1;
      } else {
        return "No response" + message;
      }
    } else if (switcher !== 4) {
      return "nginx error: " + message;
    } else {
      exit = 1;
    }
    if (exit === 1) {
      if (isServerCode(code)) {
        return "Network Error: " + message;
      } else if (isClientCode(code)) {
        return "Client Code:" + message;
      } else {
        return "Unknown code: " + (String(code) + (" message: " + message));
      }
    }
    
  }
}

var result = /* array */[
      1,
      2,
      3
    ].map((function (num) {
          return (num << 1);
        })).filter((function (num) {
        return num >= 4;
      }));

console.log(result);

function dataToJs(param) {
  return {
          name: param[/* name */0]
        };
}

function dataFromJs(param) {
  return /* record */[/* name */param.name];
}

var resultWithData = dataFromJs(JSON.parse("{\"name\": \"Luke\"}"));

console.log(resultWithData[/* name */0]);

global.draw("dog", 1, 2);

Drawing.draw("sup");

exports.myFunc = myFunc;
exports.myOtherFunc = myOtherFunc;
exports.isServerCode = isServerCode;
exports.isClientCode = isClientCode;
exports.response = response;
exports.result = result;
exports.dataToJs = dataToJs;
exports.dataFromJs = dataFromJs;
exports.resultWithData = resultWithData;
/* result Not a pure module */
