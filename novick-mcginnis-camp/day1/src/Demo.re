Js.log("Hello, BuckleScript and Reason!");

let b = (a, b) => a + b;

type person = {
  name: string,
  age: int,
};

let whoami = {name: "kal", age: 30};

Js.log("\nFloat arithmetic");
Js.log(2.0 +. 2.0);

Js.log("\nString concatenation");
Js.log("Hi" ++ " String Concat " ++ string_of_int(1));

Js.log("\nMultiline strings");
Js.log({|Multine
Strings
Are
Cool|});

Js.log("\nString interpolation w/ BuckleScript");
let myName = "Kalalau";
Js.log({j|Hi $myName|j});

Js.log("\nEquality");
Js.log("Structural equality: [1, 2, 3] == [1, 2, 3]");
Js.log([1, 2, 3] == [1, 2, 3]);
Js.log("Referential equality: [1, 2, 3] === [1, 2, 3]");
Js.log([1, 2, 3] === [1, 2, 3]);
