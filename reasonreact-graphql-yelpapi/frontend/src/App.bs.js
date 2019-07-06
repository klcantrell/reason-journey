// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var MexicanRestaurant$ReactHooksTemplate = require("./MexicanRestaurant.bs.js");

function str(prim) {
  return prim;
}

function arr(prim) {
  return prim;
}

function App(Props) {
  var match = React.useReducer((function (state, action) {
          var nextMexicanRestaurantOffset = state[/* restaurants */0].length + 1 | 0;
          return /* record */[/* restaurants */$$Array.append(state[/* restaurants */0], /* array */[React.createElement(MexicanRestaurant$ReactHooksTemplate.make, {
                              searchOffset: nextMexicanRestaurantOffset,
                              key: nextMexicanRestaurantOffset.toString()
                            })])];
        }), /* record */[/* restaurants : array */[React.createElement(MexicanRestaurant$ReactHooksTemplate.make, {
                searchOffset: 0,
                key: "0"
              })]]);
  var dispatch = match[1];
  return React.createElement("div", {
              className: "main"
            }, React.createElement("button", {
                  onClick: (function (param) {
                      return Curry._1(dispatch, /* AddRestaurant */0);
                    })
                }, "Add Restaurant"), React.createElement("div", {
                  className: "restaurants"
                }, match[0][/* restaurants */0]));
}

var make = App;

exports.str = str;
exports.arr = arr;
exports.make = make;
/* react Not a pure module */
