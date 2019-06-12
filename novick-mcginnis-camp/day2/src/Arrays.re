let myFirstArray = [|1, 2, 3|];

Js.log(myFirstArray);
Js.log(myFirstArray[0]);

let otherArray = Array.make(3, "aa");
Js.log(otherArray);

let logicArray = ArrayLabels.init(~f=i => "k" ++ string_of_int(i), 3);
Js.log(logicArray);

Js.log(Array.length(logicArray));

// causing an issue in the compiled JS for some reason
// let [|a, b|] = [|1, 2|];
// Js.log(a);
// Js.log(b);

Js.log(logicArray |> Array.to_list);
Js.log(logicArray |> Array.to_list |> Array.of_list);

let maxOfArray = arr => arr |> ArrayLabels.fold_left(~f=max, ~init=min_int);

Js.log(maxOfArray([|5, 6, 9|]));

let filterArray = (filter, arr) =>
  arr |> Array.to_list |> List.filter(filter) |> Array.of_list;

Js.log(filterArray(num => num > 2, [|1, 2, 3|]));

let alphabet =
  Array.make(26, 0)
  |> Array.mapi((i, _) => Char.chr(i + 65))
  |> Array.to_list;

let isPangram = str =>
  alphabet |> List.for_all(String.uppercase(str)->String.contains);

Js.log(isPangram("The quick brown fox jumps over the lazy dog"));
