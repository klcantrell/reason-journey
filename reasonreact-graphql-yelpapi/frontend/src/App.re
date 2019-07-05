let str = ReasonReact.string;

type actions =
  | AddRestaurant;

type state = {restaurants: array(React.element)};

[@react.component]
let make = () => {
  let ({restaurants}, _) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | AddRestaurant => {restaurants: [|React.null|]}
        },
      {restaurants: [|<MexicanRestaurant key="0" />|]},
    );
  <div> restaurants->ReasonReact.array </div>;
};
