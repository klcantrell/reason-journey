// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");

var regularList = /* :: */[
  1,
  /* :: */[
    2,
    /* :: */[
      3,
      /* [] */0
    ]
  ]
];

console.log(regularList);

var patternMatchExample = regularList ? "Head and tail " + String(1) : "Empty";

function myLengthFn(param) {
  if (param) {
    return 1 + myLengthFn(param[1]) | 0;
  } else {
    return 0;
  }
}

console.log(myLengthFn(regularList));

console.log(List.nth(regularList, 1));

console.log($$Array.of_list(List.sort(Caml_obj.caml_compare, /* :: */[
              7,
              /* :: */[
                2,
                /* :: */[
                  4,
                  /* :: */[
                    5,
                    /* [] */0
                  ]
                ]
              ]
            ])));

function removeAll(value, _l) {
  while(true) {
    var l = _l;
    if (l) {
      var tail = l[1];
      var head = l[0];
      if (head === value) {
        _l = tail;
        continue ;
      } else {
        return /* :: */[
                head,
                removeAll(value, tail)
              ];
      }
    } else {
      return /* [] */0;
    }
  };
}

console.log($$Array.of_list(List.flatten(/* :: */[
              /* :: */[
                2,
                /* :: */[
                  3,
                  /* :: */[
                    4,
                    /* [] */0
                  ]
                ]
              ],
              /* :: */[
                /* :: */[
                  10,
                  /* :: */[
                    9,
                    /* :: */[
                      1,
                      /* [] */0
                    ]
                  ]
                ],
                /* [] */0
              ]
            ])));

console.log(List.fold_left((function (a, b) {
            return a + b | 0;
          }), 0, /* :: */[
          1,
          /* :: */[
            2,
            /* :: */[
              3,
              /* [] */0
            ]
          ]
        ]));

var abc = /* Cons */[
  "s",
  /* Cons */[
    "b",
    /* Cons */[
      "C",
      /* Nada */0
    ]
  ]
];

exports.abc = abc;
exports.regularList = regularList;
exports.patternMatchExample = patternMatchExample;
exports.myLengthFn = myLengthFn;
exports.removeAll = removeAll;
/*  Not a pure module */
