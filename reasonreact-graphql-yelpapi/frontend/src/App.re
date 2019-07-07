let str = ReasonReact.string;
let arr = ReasonReact.array;

type restaurantComponent = {
  key: int,
  el: React.element,
};

type actions =
  | AddRestaurant(restaurantComponent)
  | RemoveRestaurant(int);

type state = {
  restaurants: array(restaurantComponent),
  nextOffset: int,
};

[@react.component]
let make = () => {
  let ({restaurants, nextOffset}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddRestaurant(newRestaurant) => {
            restaurants:
              Js.Array.concat([|newRestaurant|], state.restaurants),
            nextOffset: state.nextOffset + 1,
          }
        | RemoveRestaurant(key) => {
            ...state,
            restaurants:
              state.restaurants
              |> Js.Array.filter(restaurant => restaurant.key !== key),
          }
        },
      {restaurants: [||], nextOffset: 0},
    );
  React.useEffect0(() => {
    dispatch(
      AddRestaurant({
        key: 0,
        el:
          <MexicanRestaurant
            key="0"
            searchOffset=0
            onExitClick={() => dispatch(RemoveRestaurant(0))}
          />,
      }),
    );
    None;
  });
  <div className="main">
    <button
      onClick={_ =>
        dispatch(
          AddRestaurant({
            key: nextOffset,
            el:
              <MexicanRestaurant
                key={nextOffset->Js.Int.toString}
                searchOffset=nextOffset
                onExitClick={() => dispatch(RemoveRestaurant(nextOffset))}
              />,
          }),
        )
      }>
      {str("Add Restaurant")}
    </button>
    <div className="restaurants">
      {arr(restaurants |> Js.Array.map(r => r.el))}
    </div>
  </div>;
};
