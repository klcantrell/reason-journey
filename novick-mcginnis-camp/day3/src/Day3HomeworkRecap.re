// unique, reverse, and convert each to a string
let stringOfUniques =
  [8, 5, 3, 5, 2, 6, 2, 5, 8, 3, 6, 7]
  |> List.sort_uniq(compare)
  |> List.rev
  |> List.map(str => string_of_int(str));

Js.log(stringOfUniques);

Js.log(stringOfUniques |> Array.of_list);

// list nth implementation
let rec nth = (~index, list) => {
  switch (list) {
  | [] => None
  | [head, ..._] when index <= 0 => Some(head)
  | [_, ...tail] => nth(~index=index - 1, tail)
  };
};

Js.log(nth(~index=1, [1, 2, 3]));

// isogram function.  Note that Str module cannot be used in JS compilation
let isIsogram = inputString => {
  let lowercaseString = inputString |> String.lowercase;

  inputString
  |> Js.String.split("")
  |> Array.to_list
  |> List.sort_uniq(compare)
  |> List.length == String.length(lowercaseString);
};

Js.log(isIsogram("supp"));

exception OutOfRange(string);

// roman numeral
let ones =
  fun
  | '0' => ""
  | '1' => "I"
  | '2' => "II"
  | '3' => "III"
  | '4' => "IV"
  | '5' => "V"
  | '6' => "VI"
  | '7' => "VII"
  | '8' => "VIII"
  | '9' => "IX"
  | _ => raise(OutOfRange("Expected a char between '0' and '9'"));

let tens =
  fun
  | '0' => ""
  | '1' => "X"
  | '2' => "XX"
  | '3' => "XXX"
  | '4' => "XL"
  | '5' => "L"
  | '6' => "LX"
  | '7' => "LXX"
  | '8' => "LXXX"
  | '9' => "XC"
  | _ => raise(OutOfRange("Expected a char between '0' and '9'"));

let hundreds =
  fun
  | '0' => ""
  | '1' => "C"
  | '2' => "CC"
  | '3' => "CCC"
  | '4' => "CD"
  | '5' => "D"
  | '6' => "DC"
  | '7' => "DCC"
  | '8' => "DCCC"
  | '9' => "CM"
  | _ => raise(OutOfRange("Expected a char between '0' and '9'"));

let thousands =
  fun
  | '0' => ""
  | '1' => "M"
  | '2' => "MM"
  | '3' => "MMM"
  | _ => raise(OutOfRange("Expected a char between '0' and '3'"));

let toRoman = i => {
  let str = string_of_int(i);

  switch (str->String.length) {
  | 1 => str.[0]->ones
  | 2 => str.[0]->tens ++ str.[1]->ones
  | 3 => str.[0]->hundreds ++ str.[1]->tens ++ str.[2]->ones
  | 4 =>
    str.[0]->thousands ++ str.[1]->hundreds ++ str.[2]->tens ++ str.[3]->ones
  | _ => raise(OutOfRange("Expected an int between 1 and 4 digits"))
  };
};

Js.log(toRoman(31));
