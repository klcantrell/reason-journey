Js.log("\nMutation of let bindings");
let myLetBinding = "sup";
// myLetBinding = "yo"; reason won't let you mutate like this
let refMyLetBinding = ref(myLetBinding);
Js.log(refMyLetBinding.contents);
refMyLetBinding := "yo"; // this is how you mutate, lots of trouble and it doesn't mutate any originally referenced variables
Js.log(refMyLetBinding.contents);
Js.log(myLetBinding);

Js.log("\nFunctions");

let add = (num1, num2) => num1 + num2;
let add1 = add(1);
let myList = List.map(add1, [1, 2, 3]);
Js.log(myList);

let rec factorial = x => {
  switch (x) {
  | x when x <= 2 => x
  | x => x * factorial(x - 1)
  };
};

Js.log(factorial(12));

Js.log("recursion");
let fnWithUnit = () => 1 + 1;
Js.log(fnWithUnit());

Js.log("unit type");
let anotherFnWithUnit = x => {
  let notReturned = 1 + 1;
  ();
};
Js.log(anotherFnWithUnit(10));

Js.log("named arguments");
let fnWithNamedArgs = (~name, ~greeting, ~timeOfDay) => {j|$greeting, $name! Good $timeOfDay.|j};
Js.log(fnWithNamedArgs(~name="Kal", ~timeOfDay="Morning", ~greeting="Sup"));

Js.log("destructuring named arguments");
let crossProduct = (~vector1 as (a1, a2, a3), ~vector2 as (b1, b2, b3)) => (
  a2 * b3 - a3 * b2,
  a3 * b1 - a1 * b3,
  a1 * b2 - a2 * b1,
);

Js.log(crossProduct(~vector1=(1, 2, 3), ~vector2=(2, 3, 4)));

Js.log("with optional arguments");
let addWithOptional = (~x=?, ~y=?, ()) => {
  switch (x, y) {
  | (Some(x), Some(y)) => x + y
  | (Some(x), None) => x
  | (None, Some(y)) => y
  | (None, None) => 0
  };
};
Js.log(addWithOptional(~x=1, ()));
Js.log(
  "how to forward an optional to the function without unwrapping it first",
);
Js.log(addWithOptional(~x=?Some(12), ~y=4, ()));

let addWithOptionalWithDefaults = (~x=0, ~y=0, ()) => x + y;
Js.log(addWithOptionalWithDefaults(~x=3, ~y=4, ()));

Js.log("pipe operators");
Js.log(
  [4, 2, 1, 5]
  |> List.map(x => x + 1)
  |> List.filter(x => x < 5)
  |> List.sort(compare),
);

Js.log(
  "shorthand for switching on a function argument (works for single arity)",
);
let someKindOfTupleFn =
  fun
  | (_, 0) => (-1)
  | (x, y) => x / y;

// same as
let someKindOfTupleFn = tuple =>
  switch (tuple) {
  | (_, 0) => (-1)
  | (x, y) => x / y
  };
