let str = ReasonReact.string;

type actions =
  | GetRandom;

type state = {number: float};

[@bs.val] [@bs.scope "Math"] external random: unit => float = "random";

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer((_, action) =>
    switch (action) {
      | GetRandom => { number: random() }
    },
    { number: 0.0 }
  );
  let {number} = state;
  let numberToDisplay = number->Js.Float.toString;

  <div>
    <div> {str(numberToDisplay)} </div>
    <button
      onClick={_ => dispatch(GetRandom)}>
      {str("Random number, please")}
    </button>
  </div>
};
