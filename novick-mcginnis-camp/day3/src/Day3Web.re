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
[@bs.val] external setTimeout: (unit => unit, int) => float = "setTimeout"