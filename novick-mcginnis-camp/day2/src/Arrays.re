let myFirstArray = [|1, 2, 3|];

Js.log(myFirstArray);
Js.log(myFirstArray[0]);

let otherArray = Array.make(3, "aa");
Js.log(otherArray);

let logicArray = ArrayLabels.init(~f=i => "k" ++ string_of_int(i), 3);
Js.log(logicArray);

Js.log(Array.length(logicArray));

let [|a, b|] = [|1, 2|];
Js.log(a);
Js.log(b);

Js.log(logicArray |> Array.to_list);
Js.log(logicArray |> Array.to_list |> Array.of_list);

let maxOfArray = arr => arr |> ArrayLabels.fold_left(~f=max, ~init=min_int);

Js.log(maxOfArray([|5, 6, 9|]));
