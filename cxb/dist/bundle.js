#!/usr/bin/env node
!function(e){var t={};function n(r){if(t[r])return t[r].exports;var o=t[r]={i:r,l:!1,exports:{}};return e[r].call(o.exports,o,o.exports,n),o.l=!0,o.exports}n.m=e,n.c=t,n.d=function(e,t,r){n.o(e,t)||Object.defineProperty(e,t,{enumerable:!0,get:r})},n.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},n.t=function(e,t){if(1&t&&(e=n(e)),8&t)return e;if(4&t&&"object"==typeof e&&e&&e.__esModule)return e;var r=Object.create(null);if(n.r(r),Object.defineProperty(r,"default",{enumerable:!0,value:e}),2&t&&"string"!=typeof e)for(var o in e)n.d(r,o,function(t){return e[t]}.bind(null,o));return r},n.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return n.d(t,"a",t),t},n.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},n.p="",n(n.s=0)}([function(e,t,n){"use strict";var r=n(1),o=n(2),u=n(3),i=n(8),c=n(4),s=n(6),a=n(7);var l=n(9).Make([{p:"path",h:"help"},{path:".",help:!1},["path"],["help"],function(e){return console.log(e),0}]);console.log(u._1(l[0],["--path","dude"]));var f=r.parse(c.Fs[1]("test.css","utf8"));console.log(o.map(function(e){return s.caml_array_get(e.selectors,0)},f.stylesheet.rules));var p=i.watch("**/*.css");function d(e){return console.log("Detected change in "+String(e)),0}a.onChange(d,p),t.Minimist=l,t.myCss=f,t.watcher=p,t.handleChange=d},function(e,t){e.exports=require("css")},function(e,t){e.exports=require("bs-platform/lib/js/array.js")},function(e,t){e.exports=require("bs-platform/lib/js/curry.js")},function(e,t,n){"use strict";var r=n(5);var o=[function(e){return r.existsSync(e)},function(e,t){return r.readFileSync(e,t)},function(e,t,n,o){return r.writeFileSync(e,t,n,o),0}];t.Fs=o,t.Path=[],t.Process=[]},function(e,t){e.exports=require("fs")},function(e,t){e.exports=require("bs-platform/lib/js/caml_array.js")},function(e,t,n){"use strict";t.onChange=function(e,t){return t.on("change",e),0}},function(e,t){e.exports=require("chokidar")},function(e,t,n){"use strict";var r=n(10);t.Make=function(e){return[function(t){return r(t,{string:e[2],boolean:e[3],alias:e[0],default:e[1],unknown:e[4]})}]}},function(e,t){e.exports=require("minimist")}]);