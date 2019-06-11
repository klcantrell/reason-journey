// to illustrate that lists are just variants
type myList('a) =
  | Nada
  | Cons('a, myList('a));
let abc = Cons("s", Cons("b", Cons("C", Nada)));

let regularList = [1, 2, 3];
Js.log(regularList);

let patternMatchExample =
  switch (regularList) {
  | [] => "Empty"
  | [first, ...tail] => "Head and tail " ++ string_of_int(first)
  };

let rec myLengthFn =
  fun
  | [] => 0
  | [_, ...tail] => 1 + myLengthFn(tail);

Js.log(myLengthFn(regularList));

Js.log(List.nth(regularList, 1));
Js.log(Array.of_list([7, 2, 4, 5] |> List.sort(compare)));

let rec removeAll = (~value, l) => {
  switch (l) {
  | [] => []
  | [head, ...tail] when head === value => removeAll(~value, tail)
  | [head, ...tail] => [head, ...removeAll(~value, tail)]
  };
};

Js.log([[2, 3, 4], [10, 9, 1]] |> List.flatten |> Array.of_list);

Js.log([1, 2, 3] |> List.fold_left((a, b) => a + b, 0));
