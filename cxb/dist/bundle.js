#!/usr/bin/env node
!function(e){var r={};function t(n){if(r[n])return r[n].exports;var o=r[n]={i:n,l:!1,exports:{}};return e[n].call(o.exports,o,o.exports,t),o.l=!0,o.exports}t.m=e,t.c=r,t.d=function(e,r,n){t.o(e,r)||Object.defineProperty(e,r,{enumerable:!0,get:n})},t.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},t.t=function(e,r){if(1&r&&(e=t(e)),8&r)return e;if(4&r&&"object"==typeof e&&e&&e.__esModule)return e;var n=Object.create(null);if(t.r(n),Object.defineProperty(n,"default",{enumerable:!0,value:e}),2&r&&"string"!=typeof e)for(var o in e)t.d(n,o,function(r){return e[r]}.bind(null,o));return n},t.n=function(e){var r=e&&e.__esModule?function(){return e.default}:function(){return e};return t.d(r,"a",r),r},t.o=function(e,r){return Object.prototype.hasOwnProperty.call(e,r)},t.p="",t(t.s=0)}([function(e,r,t){"use strict";var n=t(1),o=t(6),u=t(2),i=t(5),s=t(7),c=t(3).Make([{p:"path",h:"help"},{path:".",help:!1}]),a=u._3(c[0],"path","help",function(e){return console.log(e),0});console.log(u._2(c[1],a,["--path","dude"]));var f=n.parse(i.Fs[1]("test.css","utf8"));console.log(o.map(function(e){return s.caml_array_get(e.selectors,0)},f.stylesheet.rules)),r.Minimist=c,r.options=a,r.myCss=f},function(e,r){e.exports=require("css")},function(e,r){e.exports=require("bs-platform/lib/js/curry.js")},function(e,r,t){"use strict";var n=t(4);r.Make=function(e){var r=e[0],t=e[1];return[function(e){return function(n){return function(o){return{string:e,boolean:n,alias:r,default:t,unknown:o}}}},function(e,r){return n(r,e)}]}},function(e,r){e.exports=require("minimist")},function(e,r,t){"use strict";var n=t(8);var o=[function(e){return n.existsSync(e)},function(e,r){return n.readFileSync(e,r)},function(e,r,t,o){return n.writeFileSync(e,r,t,o),0}];r.Fs=o,r.Path=[],r.Process=[]},function(e,r){e.exports=require("bs-platform/lib/js/array.js")},function(e,r){e.exports=require("bs-platform/lib/js/caml_array.js")},function(e,r){e.exports=require("fs")}]);