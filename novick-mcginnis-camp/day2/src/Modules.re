// each file is a module.  everything in a module seems to be executed when you load it somewhere else
module ArraysToolbox = {
  let checkPangram = Arrays.isPangram;
};

Js.log(
  ArraysToolbox.checkPangram("The quick brown fox jumps over the lazy dog"),
);

module type MathToolsInterface = {
  let times: (int, int) => int;
  let square: int => int;
  let coolGreeting: string => string;
};

module Math: MathToolsInterface = {
  include Hi;
  let coolGreeting = str => yo(str);
  let times = (x, y) => x * y;
  let square = x => times(x, x);
};
