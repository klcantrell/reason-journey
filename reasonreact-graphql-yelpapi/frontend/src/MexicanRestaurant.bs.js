// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonApollo = require("reason-apollo/src/ReasonApollo.bs.js");

function str(prim) {
  return prim;
}

function MexicanRestaurant$RestaurantCard(Props) {
  var info = Props.info;
  return React.createElement("div", undefined, React.createElement("p", undefined, info[/* name */0]), React.createElement("img", {
                  src: info[/* url */1]
                }));
}

var RestaurantCard = /* module */[/* make */MexicanRestaurant$RestaurantCard];

var ppx_printed_query = "query getMexicanRestaurant($location: String, $limit: Int, $offset: Int)  {\nsearch(location: $location, limit: $limit, offset: $offset)  {\ntotal  \nbusiness  {\nname  \nphotos  \n}\n\n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "search");
    var tmp;
    if (match$1 !== undefined) {
      var value$1 = Caml_option.valFromOption(match$1);
      var match$2 = Js_json.decodeNull(value$1);
      if (match$2 !== undefined) {
        tmp = undefined;
      } else {
        var match$3 = Js_json.decodeObject(value$1);
        var tmp$1;
        if (match$3 !== undefined) {
          var value$2 = Caml_option.valFromOption(match$3);
          var match$4 = Js_dict.get(value$2, "total");
          var tmp$2;
          if (match$4 !== undefined) {
            var value$3 = Caml_option.valFromOption(match$4);
            var match$5 = Js_json.decodeNull(value$3);
            if (match$5 !== undefined) {
              tmp$2 = undefined;
            } else {
              var match$6 = Js_json.decodeNumber(value$3);
              tmp$2 = match$6 !== undefined ? match$6 | 0 : Js_exn.raiseError("graphql_ppx: Expected int, got " + JSON.stringify(value$3));
            }
          } else {
            tmp$2 = undefined;
          }
          var match$7 = Js_dict.get(value$2, "business");
          var tmp$3;
          if (match$7 !== undefined) {
            var value$4 = Caml_option.valFromOption(match$7);
            var match$8 = Js_json.decodeNull(value$4);
            if (match$8 !== undefined) {
              tmp$3 = undefined;
            } else {
              var match$9 = Js_json.decodeArray(value$4);
              tmp$3 = match$9 !== undefined ? match$9.map((function (value) {
                        var match = Js_json.decodeNull(value);
                        if (match !== undefined) {
                          return undefined;
                        } else {
                          var match$1 = Js_json.decodeObject(value);
                          var tmp;
                          if (match$1 !== undefined) {
                            var value$1 = Caml_option.valFromOption(match$1);
                            var match$2 = Js_dict.get(value$1, "name");
                            var tmp$1;
                            if (match$2 !== undefined) {
                              var value$2 = Caml_option.valFromOption(match$2);
                              var match$3 = Js_json.decodeNull(value$2);
                              if (match$3 !== undefined) {
                                tmp$1 = undefined;
                              } else {
                                var match$4 = Js_json.decodeString(value$2);
                                tmp$1 = match$4 !== undefined ? match$4 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$2));
                              }
                            } else {
                              tmp$1 = undefined;
                            }
                            var match$5 = Js_dict.get(value$1, "photos");
                            var tmp$2;
                            if (match$5 !== undefined) {
                              var value$3 = Caml_option.valFromOption(match$5);
                              var match$6 = Js_json.decodeNull(value$3);
                              if (match$6 !== undefined) {
                                tmp$2 = undefined;
                              } else {
                                var match$7 = Js_json.decodeArray(value$3);
                                tmp$2 = match$7 !== undefined ? match$7.map((function (value) {
                                          var match = Js_json.decodeNull(value);
                                          if (match !== undefined) {
                                            return undefined;
                                          } else {
                                            var match$1 = Js_json.decodeString(value);
                                            return match$1 !== undefined ? match$1 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value));
                                          }
                                        })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$3));
                              }
                            } else {
                              tmp$2 = undefined;
                            }
                            tmp = {
                              name: tmp$1,
                              photos: tmp$2
                            };
                          } else {
                            tmp = Js_exn.raiseError("graphql_ppx: Object is not a value");
                          }
                          return Caml_option.some(tmp);
                        }
                      })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$4));
            }
          } else {
            tmp$3 = undefined;
          }
          tmp$1 = {
            total: tmp$2,
            business: tmp$3
          };
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Object is not a value");
        }
        tmp = Caml_option.some(tmp$1);
      }
    } else {
      tmp = undefined;
    }
    return {
            search: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make($$location, limit, offset, param) {
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "location",
                  $$location !== undefined ? $$location : null
                ],
                /* tuple */[
                  "limit",
                  limit !== undefined ? limit : null
                ],
                /* tuple */[
                  "offset",
                  offset !== undefined ? offset : null
                ]
              ]),
          parse: parse
        };
}

function makeWithVariables(variables) {
  var $$location = variables.location;
  var limit = variables.limit;
  var offset = variables.offset;
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "location",
                  $$location !== undefined ? $$location : null
                ],
                /* tuple */[
                  "limit",
                  limit !== undefined ? limit : null
                ],
                /* tuple */[
                  "offset",
                  offset !== undefined ? offset : null
                ]
              ]),
          parse: parse
        };
}

function ret_type(f) {
  return /* module */[];
}

var MT_Ret = /* module */[];

var GetMexicanRestaurant = /* module */[
  /* ppx_printed_query */ppx_printed_query,
  /* query */ppx_printed_query,
  /* parse */parse,
  /* make */make,
  /* makeWithVariables */makeWithVariables,
  /* ret_type */ret_type,
  /* MT_Ret */MT_Ret
];

var GetMexicanRestaurantQuery = ReasonApollo.CreateQuery([
      ppx_printed_query,
      parse
    ]);

function MexicanRestaurant(Props) {
  var mexicanRestaurantQuery = make("indianapolis", 1, 1, /* () */0);
  return React.createElement(GetMexicanRestaurantQuery[/* make */4], {
              variables: mexicanRestaurantQuery.variables,
              children: (function (param) {
                  var result = param[/* result */0];
                  if (typeof result === "number") {
                    return React.createElement("div", undefined, "Loading...");
                  } else if (result.tag) {
                    return React.createElement("div", undefined, Belt_Option.mapWithDefault(Belt_Option.flatMap(Belt_Option.flatMap(result[0].search, (function (search) {
                                              return search.business;
                                            })), (function (businesses) {
                                          return Caml_array.caml_array_get(businesses, 0);
                                        })), null, (function (business) {
                                      var businessName = Belt_Option.getWithDefault(business.name, "");
                                      var photos = Belt_Option.getWithDefault(business.photos, /* array */[]);
                                      var firstPhoto = Belt_Option.getWithDefault(Caml_array.caml_array_get(photos, 0), "");
                                      var info = /* record */[
                                        /* name */businessName,
                                        /* url */firstPhoto
                                      ];
                                      return React.createElement(MexicanRestaurant$RestaurantCard, {
                                                  info: info
                                                });
                                    })));
                  } else {
                    return React.createElement("div", undefined, result[0].message);
                  }
                })
            });
}

var make$1 = MexicanRestaurant;

exports.str = str;
exports.RestaurantCard = RestaurantCard;
exports.GetMexicanRestaurant = GetMexicanRestaurant;
exports.GetMexicanRestaurantQuery = GetMexicanRestaurantQuery;
exports.make = make$1;
/* GetMexicanRestaurantQuery Not a pure module */