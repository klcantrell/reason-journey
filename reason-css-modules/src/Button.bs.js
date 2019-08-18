// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ButtonCss = require("./Button.css");

var styles = ButtonCss;

function make(classes) {
  return $$Array.fold_left((function (acc, class_) {
                if (acc === "") {
                  return acc + class_;
                } else {
                  return acc + (" " + class_);
                }
              }), "", classes);
}

var Cx = /* module */[/* make */make];

function styleOfColor(color) {
  if (color >= 756711075) {
    return (function (prim) {
        return prim.green;
      });
  } else {
    return (function (prim) {
        return prim.purple;
      });
  }
}

function styleOfSize(size) {
  if (size !== 311976103) {
    if (size >= 861718677) {
      return (function (prim) {
          return prim.medium;
        });
    } else {
      return (function (prim) {
          return prim.large;
        });
    }
  } else {
    return (function (prim) {
        return prim.small;
      });
  }
}

function Button(Props) {
  var children = Props.children;
  var match = Props.color;
  var color = match !== undefined ? match : /* Purple */639527516;
  var match$1 = Props.size;
  var size = match$1 !== undefined ? match$1 : /* Medium */861718677;
  return React.createElement("button", {
              className: make(/* array */[
                    styles.base,
                    styleOfColor(color)(styles),
                    styleOfSize(size)(styles)
                  ])
            }, children);
}

var make$1 = Button;

exports.styles = styles;
exports.Cx = Cx;
exports.styleOfColor = styleOfColor;
exports.styleOfSize = styleOfSize;
exports.make = make$1;
/* styles Not a pure module */
