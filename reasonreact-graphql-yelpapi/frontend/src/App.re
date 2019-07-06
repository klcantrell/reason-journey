let str = ReasonReact.string;
let arr = ReasonReact.array;

type actions =
  | AddRestaurant;

type state = {restaurants: array(React.element)};

[@react.component]
let make = () => {
  let ({restaurants}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddRestaurant =>
          let nextMexicanRestaurantOffset =
            state.restaurants->Array.length + 1;
          {
            restaurants:
              Array.append(
                state.restaurants,
                [|
                  <MexicanRestaurant
                    key={nextMexicanRestaurantOffset->Js.Int.toString}
                    searchOffset=nextMexicanRestaurantOffset
                  />,
                |],
              ),
          };
        },
      {restaurants: [|<MexicanRestaurant key="0" searchOffset=0 />|]},
    );
  <div className="main">
    <button onClick={_ => dispatch(AddRestaurant)}>
      "Add Restaurant"->str
    </button>
    <div className="restaurants"> restaurants->arr </div>
  </div>;
};
