let str = ReasonReact.string;

type state = {number: float};

[@bs.val] [@bs.scope "Math"] external random: unit => float = "random";

let floatMultiplied = float => float *. 10000000.00;
let intDivided = int => int / 10000000;
let randomFloat = () => {
  random()->floatMultiplied->int_of_float->intDivided->float_of_int;
};

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => {number: 0.0});
  let numberToDisplay = state.number->string_of_float;

  <div>
    <div> {str(numberToDisplay)} </div>
    <button
      onClick={e =>
        setState(_ => {number: random()})
      }>
      {str("Random number, please")}
    </button>
  </div>
};
