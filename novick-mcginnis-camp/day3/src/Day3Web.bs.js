// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

console.log("sup");

var world = "World";

console.log("World nice");

var helloWorld = "Hello, " + (String(world) + "");

console.log(helloWorld);

var exponent = (82.123).toExponential();

console.log(exponent);

console.log("123".split(""));

var addFunction = ((a, b) => {
  return a + b
});

console.log(Curry._2(addFunction, 1, 2));

const myRawVariable = 'sup'
;

console.log(myRawVariable)
;

exports.world = world;
exports.helloWorld = helloWorld;
exports.exponent = exponent;
exports.addFunction = addFunction;
/*  Not a pure module */
