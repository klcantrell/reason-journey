// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ArrayLabels = require("bs-platform/lib/js/arrayLabels.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

var myFirstArray = /* array */[
  1,
  2,
  3
];

console.log(myFirstArray);

console.log(Caml_array.caml_array_get(myFirstArray, 0));

var otherArray = Caml_array.caml_make_vect(3, "aa");

console.log(otherArray);

var logicArray = ArrayLabels.init(3, (function (i) {
        return "k" + String(i);
      }));

console.log(logicArray);

console.log(logicArray.length);

var match = /* array */[
  1,
  2
];

if (match.length !== 2) {
  throw [
        Caml_builtin_exceptions.match_failure,
        /* tuple */[
          "Arrays.re",
          14,
          4
        ]
      ];
} else {
  var a = match[0];
  var b = match[1];
  console.log(a);
  console.log(b);
  console.log($$Array.to_list(logicArray));
  console.log($$Array.of_list($$Array.to_list(logicArray)));
  var maxOfArray = function (arr) {
    return ArrayLabels.fold_left(Caml_obj.caml_max, Pervasives.min_int, arr);
  };
  console.log(maxOfArray(/* array */[
            5,
            6,
            9
          ]));
  /* module */[
    /* myFirstArray */myFirstArray,
    /* otherArray */otherArray,
    /* logicArray */logicArray,
    /* a */a,
    /* b */b,
    /* maxOfArray */maxOfArray
  ];
}

/*  Not a pure module */
