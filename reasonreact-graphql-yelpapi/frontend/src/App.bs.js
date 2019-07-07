// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
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
          if (action.tag) {
            var key = action[0];
            return /* record */[
                    /* restaurants */state[/* restaurants */0].filter((function (restaurant) {
                            return restaurant[/* key */0] !== key;
                          })),
                    /* nextOffset */state[/* nextOffset */1]
                  ];
          } else {
            return /* record */[
                    /* restaurants */state[/* restaurants */0].concat(/* array */[action[0]]),
                    /* nextOffset */state[/* nextOffset */1] + 1 | 0
                  ];
          }
        }), /* record */[
        /* restaurants : array */[],
        /* nextOffset */0
      ]);
  var dispatch = match[1];
  var match$1 = match[0];
  var nextOffset = match$1[/* nextOffset */1];
  React.useEffect((function () {
          Curry._1(dispatch, /* AddRestaurant */Block.__(0, [/* record */[
                    /* key */0,
                    /* el */React.createElement(MexicanRestaurant$ReactHooksTemplate.make, {
                          searchOffset: 0,
                          onExitClick: (function (param) {
                              return Curry._1(dispatch, /* RemoveRestaurant */Block.__(1, [0]));
                            }),
                          key: "0"
                        })
                  ]]));
          return undefined;
        }), ([]));
  return React.createElement("div", {
              className: "main"
            }, React.createElement("button", {
                  onClick: (function (param) {
                      return Curry._1(dispatch, /* AddRestaurant */Block.__(0, [/* record */[
                                      /* key */nextOffset,
                                      /* el */React.createElement(MexicanRestaurant$ReactHooksTemplate.make, {
                                            searchOffset: nextOffset,
                                            onExitClick: (function (param) {
                                                return Curry._1(dispatch, /* RemoveRestaurant */Block.__(1, [nextOffset]));
                                              }),
                                            key: nextOffset.toString()
                                          })
                                    ]]));
                    })
                }, "Add Restaurant"), React.createElement("div", {
                  className: "restaurants"
                }, match$1[/* restaurants */0].map((function (r) {
                        return r[/* el */1];
                      }))));
}

var make = App;

exports.str = str;
exports.arr = arr;
exports.make = make;
/* react Not a pure module */
