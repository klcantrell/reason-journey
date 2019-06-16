Js.log("sup");

let world = "World";

Js.log(world ++ " nice");

let helloWorld = {j|Hello, $world|j};

Js.log(helloWorld);

let exponent = Js.Float.toExponential(82.123);

Js.log(exponent);

Js.log("123" |> Js.String.split(""));

let addFunction: (int, int) => int = [%raw {|(a, b) => {
  return a + b
}|}];

Js.log(addFunction(1, 2));

%raw
"const myRawVariable = 'sup'";

%raw
"console.log(myRawVariable)";

type timeout;
[@bs.val] external setTimeout: (unit => unit, int) => timeout = "setTimeout";

[@bs.val] external clearTimeout: (timeout => unit) = "clearTimeout";

let myTimeout = setTimeout(() => {
  Js.log("yo yo yo");
}, 1000);

// clearTimeout(myTimeout);

[@bs.scope "Math"] [@bs.val] external random: (int) => float = "random";

Js.log(random(23));

[@bs.scope ("window", "location", "ancestorOrigins")] [@bs.val] external ancestorOriginsLength: int = "length";

Js.log(ancestorOriginsLength);

[@bs.module "someNpmModuleForInstance"] external someBindingInThatModuleThatCouldBeNull: Js.Nullable.t(string) = "myId";

let jsMap: Js.Dict.t(string) = Js.Dict.empty();
Js.Dict.set(jsMap, "Kal", "dude");
Js.log(jsMap);

// get values from JS


[@bs.val] external personAge: Js.Dict.t(int) = "personAge";

switch(Js.Dict.get(personAge, "Kal")) {
  | None => Js.log("Kal is not found")
  | Some(age) => Js.log("Kal is " ++ string_of_int(age))
}

// type person = Js.t({
//   .
//   name: string,
//   lastName: string,
//   age: int,
// });

[@bs.deriving abstract]
type person = {
  name: string,
  lastName: string,
  age: int,
};


[@bs.val] external getPerson: unit => person = "getPerson";

// Js.log(getPerson()##lastName); // using Js.t

Js.log(lastName(getPerson()));

[@bs.deriving abstract]
type testRecord = {
  [@bs.as "type"] test: string,
  test2: string,
  [@bs.optional] test3: string,
};

[@bs.val] external printTest: testRecord => unit = "printTest";

// let testRecord = {
//   test: "hey",
//   test2: "there",
// };

let myTestRecord = testRecord(~test="hey", ~test2="there", ());

printTest(myTestRecord);

type date;
[@bs.new] external createDate: unit => date = "Date";

let date = createDate();

Js.log(date);

type myMath;
[@bs.val] external math: myMath = "Math";
[@bs.send] external rnd: (myMath, int) => float = "random" ;
Js.log(rnd(math, 23));

[@bs.deriving { jsConverter: newType }]
type myPerson = {
  birthDate: string,
  pet: string,
  married: bool,
};

[@bs.val] external getMyPerson: unit => abs_myPerson = "getMyPerson";

let personFromJs = myPersonFromJs(getMyPerson());

Js.log(personFromJs.married);
