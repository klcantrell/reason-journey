// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function str(prim) {
  return prim;
}

function handleClick(_event) {
  alert("You clicked!");
  return /* () */0;
}

function Component3(Props) {
  return React.createElement("div", undefined, React.createElement("div", undefined, "Sup"), React.createElement("button", {
                  onClick: handleClick
                }, "YO"));
}

var make = Component3;

exports.str = str;
exports.handleClick = handleClick;
exports.make = make;
/* react Not a pure module */
