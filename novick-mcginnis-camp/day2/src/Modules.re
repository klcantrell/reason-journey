// each file is a module.  everything in a module seems to be executed when you load it somewhere else
module ArraysToolbox = {
  let checkPangram = Arrays.isPangram;
};

Js.log(
  ArraysToolbox.checkPangram("The quick brown fox jumps over the lazy dog"),
);

module Math = {
  module Tools = {
    let times = (x, y) => y * y;
    let square = x => times(x, x);
  };
};

Js.log(Math.Tools.square(3));
