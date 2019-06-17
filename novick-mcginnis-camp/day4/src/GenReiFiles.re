Js.log("Hello, BuckleScript and Reason!");

Js.log("\nFloat arithmetic");
Js.log(2.0 +. 2.0);

Js.log("\nString concatenation");
Js.log("Hi" ++ " String Concat " ++ string_of_int(1));

Js.log("\nMultiline strings");
Js.log({|Multiline
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
// Js.log(true == 1) reason won't let you do this

Js.log("\nArithmetic");
Js.log(10 / 3);
// Js.log("10" + 10); reason won't let you do this
Js.log(20.0 *. 1e3);

Js.log("\nConditionals");
let conditionallyAssignThis = if (true) {"Hey"} else {"Sup"}; // probably won't be doing this a lot with pattern matching
// let conditionalBranchesMustBeSameType = true ? "Hey" : 1; this won't work
Js.log(conditionallyAssignThis);

Js.log("\nBindings");
let testBinding = "sup";
// testBinding = "dude"; won't work
let testBinding = "dude"; // shadowing
let testBinding: string = "yo" /* can annotate types if needed*/;

{
  let testBinding = "man";
  Js.log(testBinding);
};

Js.log(testBinding);
let lastExpressionIsReturned = {
  let firstName = "kal";
  let lastName = " cantrell";
  firstName ++ lastName;
};
Js.log(lastExpressionIsReturned);

Js.log("\nTuples");
let myFirstTuple = ("Kal", 23);
Js.log(fst(myFirstTuple));
Js.log("Destructuring tuples");
let (tupVal1, tupVal2) = myFirstTuple;
Js.log(tupVal2);
let (_, onlyWantTup2) = myFirstTuple;
Js.log(onlyWantTup2);

Js.log("\nRecords");

type person = {
  name: string,
  age: int,
};

let whoAmI = {name: "kal", age: 30};
let whoAmI = {...whoAmI, age: whoAmI.age + 1};
Js.log(whoAmI.age);
/* let willNotWorkWithoutTypeDefinition = { name: "kal" }*/
type rocket = {
  rocketType: string,
  mutable destination: string,
  fuelType: string,
};

type rocketDestination('a) = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates('a),
}
and celestialCoordinates('a) = {
  ra: ('a, 'a, 'a),
  dec: ('a, 'a, 'a),
};

let rocketToMars = {
  rocketType: "SpaceX Falcon 9",
  destination: "Moon",
  fuelType: "RP-1",
};

rocketToMars.destination = "Mars";
Js.log(rocketToMars);

let marsDestination = {
  destinationName: "Mars",
  constellation: "Pisces",
  coordinates: {
    ra: ("21h", "10m", "44s"),
    dec: ("52deg", "53min", "11s"),
  },
};

Js.log(marsDestination);

Js.log("\nVariants");

type myFirstVariant =
  | This
  | That;
Js.log(That);

type point =
  | Point(float, float);

let myPointInstance = Point(2.3, 3.4);
Js.log(myPointInstance);

type shape =
  | Rectangle(point, point)
  | Circle(point, float);

Js.log(Rectangle(Point(1.2, 3.4), Point(6.7, 5.4)));

Js.log("\nOption type");
type usingOptionalType = {name: option(string)};

let me = {name: Some("Kal")};

Js.log("\nPattern Matching and destructuring");
type myRecord = {myField: (string, string)};

let myRecordInstance = {myField: ("sup", "yo")};

let {myField: (_, greeting)} = myRecordInstance;
Js.log(greeting);

let myTuple = (1, 3);
let isKal = name => name == "Kal";
let result =
  switch (myTuple) {
  | (1, y) when isKal("Kal") => "First " ++ string_of_int(y)
  | (x, 0)
  | (0, x) => "First or second is zero, X: " ++ string_of_int(x)
  | (8, x) as tup =>
    let (y, _) = tup;
    "Hey ( " ++ string_of_int(y) ++ ", " ++ string_of_int(x) ++ ")";
  | (x, y) => string_of_int(x + y)
  };
Js.log(result);

Js.log("\nExercises");
// let exchange = int => {
//   let inputAsString = int->string_of_int;
//   let inputAsStringTuple = (
//     inputAsString.[0] |> String.make(1),
//     inputAsString.[1] |> String.make(1),
//   );
//   let (a, b) = inputAsStringTuple;
//   int_of_string(b ++ a);
// };
let exchange = num => {
  let (first, second) = (num / 10, num mod 10);
  second * 10 + first;
};
Js.log(exchange(73));

// command for genereating rei file
// bsc -bs-re-out lib/bs/src/GenReiFiles-Day4.cmi > src/GenReiFiles.rei