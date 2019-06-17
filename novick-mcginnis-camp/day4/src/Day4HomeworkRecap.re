let myFunc = (name: 'a): unit => Js.log(name);

let myOtherFunc: 'a => unit = name => Js.log(name);

type person = {
  name: string,
  age: int
}

let isServerCode = (code) => code / 100 == 5;
let isClientCode = (code) => code / 100 == 5;
type request = Loading | Error(string, int) | Success(person);
let response = 
  fun
  | Loading => "Loading"
  | Error(message, 444) => "No response" ++ message
  | Error(message, 494 | 495 | 496 | 497 | 499) => "nginx error: " ++ message
  | Error(message, code) when isServerCode(code) => "Network Error: " ++ message
  | Error(message, code) when isClientCode(code) => "Client Code:" ++ message
  | Error(message, x) => "Unknown code: " ++ string_of_int(x) ++ " message: " ++ message
  | Success({ name: "Vladimir Novick" }) => "Howdy Vladimir"
  | Success(response) => response.name;

  // emphasizing [@bs.send]

[@bs.send] external map: (array('a), 'a => 'b) => array('b) = "map";
[@bs.send] external filter: (array('a), 'a => 'b) => array('b) = "filter";

let result = [|1, 2, 3|] -> map(num => num * 2) -> filter(num => num >= 4);

Js.log(result)

[@bs.deriving { jsConverter: newType }]
type data = {
  name: string,
};

[@bs.scope "JSON"] [@bs.val] external parseIntoMyData: string => abs_data = "parse";

let resultWithData = parseIntoMyData("{\"name\": \"Luke\"}") -> dataFromJs;

Js.log(resultWithData.name);

// how to handle binding to a JS function that has several signatures

[@bs.val] [@bs.scope "global"] [@bs.variadic] external draw: ([@bs.as "dog"] _, array(int)) => unit = "draw";

draw([|1, 2|]);

[@bs.module "Drawing"] external drawCat: unit => unit = "draw";
[@bs.module "Drawing"] external drawDog: (~giveName: string) => unit = "draw";
[@bs.module "Drawing"] external draw: (string, ~useRandomAnimal: bool) => unit = "draw";

drawDog(~giveName="sup");