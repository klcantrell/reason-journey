module Count: FunctorExample.Count = {
  let count = 4;
}

module Repeat = FunctorExample.Make(Count);

Js.log(Repeat.repeat("abc\n"));