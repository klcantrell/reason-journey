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
};

[@bs.deriving {jsConverter: newType}]
type pokemon = {
  name: string,
  _type: pokemonTypes,
  level: int,
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
         ): pokemonUntyped
       )
     );
};

let pokemonDataTyped = bringInPokemonFromJs(pokemonData);

Js.log("[Reason]: Process Pokemon");
Js.log(
  pokemonDataTyped
  |> Js.Array.filter(
       fun
       | {name: _, level, _type: `Electric} when level > 70 => true
       | _ => false,
     )
  |> formatPokemonForJs,
);

// Reason React

let str = ReasonReact.string;
let filter = Js.Array.filter;
let map = Js.Array.map;

module App = {
  [@react.component]
  let make = (~pokemon) => {
    <div>
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
         |> map(p => <div key={p.name}> {str(p.name)} </div>),
       )}
    </div>;
  };
};

ReactDOMRe.renderToElementWithId(
  <App pokemon=pokemonDataTyped />,
  "reason-app",
);
