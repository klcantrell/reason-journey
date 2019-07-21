[@bs.module] external myExternalJs: unit = "./External";

// PRACTICE WITH ARRAY PROCESSING

let longest = (str1, str2) => {
  let combinedStr = str1 ++ str2;
  combinedStr
  |> Js.String.split("")
  |> Js.Array.reduce(
       (acc, char) =>
         char->Js.Array.includes(acc)
           ? acc : Js.Array.concat([|char|], acc),
       [||],
     )
  |> Js.Array.sortInPlace
  |> Js.Array.joinWith("");
};

// QUESTIONS

type questionCategory =
  | Math
  | Science;

type wrongness =
  | Close
  | Kinda
  | Very;

type questionState =
  | Wrong(wrongness)
  | Correct;

type answeredQuestion = {
  number: int,
  state: questionState,
  category: questionCategory,
};

let answeredQuestions = [|
  {number: 1, state: Wrong(Very), category: Math},
  {number: 2, state: Wrong(Kinda), category: Science},
  {number: 3, state: Correct, category: Math},
|];

Js.log("[Reason]: Process answers");
Js.log(
  answeredQuestions
  |> Js.Array.filter(
       fun
       | {number: _, state: Wrong(_), category: Science} => true
       | _ => false,
     )
  |> Js.Array.map(q => q.number),
);

// POKEMON

[@bs.deriving {jsConverter: newType}]
type pokemonTypes = [ | [@bs.as "ELECTRIC"] `Electric | [@bs.as "FIRE"] `Fire];

[@bs.deriving abstract]
type pokemonUntyped = {
  name: string,
  [@bs.as "type"]
  _type: abs_pokemonTypes,
  level: int,
  image: string,
};

[@bs.deriving {jsConverter: newType}]
type pokemon = {
  name: string,
  _type: pokemonTypes,
  level: int,
  image: string,
};

[@bs.module "./External"]
external pokemonData: Js.Array.t(pokemonUntyped) = "pokemon";

// JS INTEROP HELPERS

let bringInPokemonFromJs = jsPokemon => {
  jsPokemon
  |> Js.Array.map((pokemon: pokemonUntyped) =>
       (
         {
           name: pokemon->nameGet,
           level: pokemon->levelGet,
           _type: pokemonTypesFromJs(pokemon->_typeGet),
           image: pokemon->imageGet,
         }: pokemon
       )
     );
};

let formatPokemonForJs = rePokemon => {
  rePokemon
  |> Js.Array.map((pokemon: pokemon) =>
       (
         pokemonUntyped(
           ~name=pokemon.name,
           ~level=pokemon.level,
           ~_type=pokemonTypesToJs(pokemon._type),
           ~image=pokemon.image,
         ): pokemonUntyped
       )
     );
};

let pokemonDataTyped = bringInPokemonFromJs(pokemonData);

// Reason React

let str = ReasonReact.string;
let filter = Js.Array.filter;
let map = Js.Array.map;

module App = {
  [@react.component]
  let make = (~pokemon) => {
    <div className="reason-app app">
      <h2> {str("Reason React")} </h2>
      {React.array(
         pokemon
         |> filter(
              fun
              | {name: _, level, _type: `Electric | `Fire}
                  when level > 70 || level < 10 =>
                true
              | _ => false,
            )
         |> map(p =>
              <figure key={p.name} className="pokemon">
                <img src={p.image} />
                <figcaption> {str(p.name)} </figcaption>
              </figure>
            ),
       )}
    </div>;
  };
};

ReactDOMRe.renderToElementWithId(
  <App pokemon=pokemonDataTyped />,
  "reason-app",
);

module Async = {
  let let_ =
      (promise: Js.Promise.t('a), continue: 'a => Js.Promise.t('b))
      : Js.Promise.t('b) =>
    promise |> Js.Promise.then_(x => continue(x));
};

let fetchFromCache = (): Js.Promise.t(string) =>
  Js.Promise.make((~resolve, ~reject as _) =>
    Js.Global.setTimeout(() => resolve(. "foo"), 10) |> ignore
  );

let fetchFromDb = (): Js.Promise.t(string) =>
  Js.Promise.make((~resolve, ~reject as _) =>
    Js.Global.setTimeout(() => resolve(. "bar"), 10) |> ignore
  );

let testFn: Js.Promise.t(unit) = {
  let%Async fromCache = fetchFromCache();
  let%Async fromDb = fetchFromDb();
  Js.log2("FROM CACHE", fromCache);
  Js.log2("FROM DB", fromDb);
  Js.Promise.resolve();
};
