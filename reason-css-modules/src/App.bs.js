// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var AppCss = require("./App.css");
var GlobalCss = require("./global.css");

var styles = AppCss;

function handleClick(_event) {
  alert("clicked!");
  return /* () */0;
}

function App(Props) {
  var message = Props.message;
  return React.createElement("div", {
              className: styles.app,
              onClick: handleClick
            }, message, React.createElement("p", undefined, "This should be blue"));
}

var globalStyles = /* () */0;

var make = App;

exports.globalStyles = globalStyles;
exports.styles = styles;
exports.handleClick = handleClick;
exports.make = make;
/*  Not a pure module */
