import React from 'react';
import ReactDOM from 'react-dom';

// QUESTIONS

// const QUESTION_STATE = {
//   WRONG: {
//     CLOSE: 1,
//     KINDA: 2,
//     VERY: 3,
//   },
//   CORRECT: 4,
// };

const QUESTION_CATEGORY = {
  SCIENCE: 'SCIENCE',
  MATH: 'MATH',
};

class QuestionState {
  constructor(state) {
    this.state = state;
  }
  toString() {
    return `QuestionState.${this.state}`;
  }
}

class WrongState extends QuestionState {}
class CorrectState extends QuestionState {}

QuestionState.CORRECT = new CorrectState('CORRECT');
QuestionState.WRONG = WrongState;
QuestionState.WRONG.CLOSE = new WrongState('CLOSE');
QuestionState.WRONG.KINDA = new WrongState('KINDA');
QuestionState.WRONG.VERY = new WrongState('VERY');

function isQuestionStateInstanceOf(
  enumeratedQuestionType,
  comparisonQuestionType
) {
  if (typeof enumeratedQuestionType === 'function') {
    return comparisonQuestionType instanceof enumeratedQuestionType;
  }
  return Object.is(comparisonQuestionType, enumeratedQuestionType);
}

// const answeredQuestions = [
//   {
//     number: 1,
//     state: QUESTION_STATE.WRONG.VERY,
//   },
//   {
//     number: 2,
//     state: QUESTION_STATE.WRONG.KINDA,
//   },
//   {
//     number: 3,
//     state: QUESTION_STATE.CORRECT,
//   },
// ];

// console.log(
//   'Process answers from JS\n',
//   answeredQuestions
//     .filter(q =>
//       Object.values(QUESTION_STATE.WRONG).some(wrongState => {
//         return q.state === wrongState;
//       })
//     )
//     .map(q => {
//       return q.number;
//     })
// );

const answeredQuestions = [
  {
    number: 1,
    state: QuestionState.WRONG.VERY,
    category: QUESTION_CATEGORY.MATH,
  },
  {
    number: 2,
    state: QuestionState.WRONG.KINDA,
    category: QUESTION_CATEGORY.SCIENCE,
  },
  {
    number: 3,
    state: QuestionState.CORRECT,
    category: QUESTION_CATEGORY.MATH,
  },
];

console.log('[JS]: Process answers\n');
console.log(
  answeredQuestions
    .filter(q => isQuestionStateInstanceOf(QuestionState.WRONG, q.state))
    .filter(q => q.category === QUESTION_CATEGORY.SCIENCE)
    .map(q => {
      return q.number;
    })
);

// POKEMON

const POKEMON_TYPES = {
  ELECTRIC: 'ELECTRIC',
  FIRE: 'FIRE',
};

export const pokemon = [
  {
    name: 'Pikachu',
    type: POKEMON_TYPES.ELECTRIC,
    level: 88,
  },
  {
    name: 'Zapdos',
    type: POKEMON_TYPES.ELECTRIC,
    level: 50,
  },
  {
    name: 'Charmander',
    type: POKEMON_TYPES.FIRE,
    level: 5,
  },
];

console.log('[JS]: Process Pokemon');
console.log(
  pokemon.filter(p => {
    return (
      (p.type === POKEMON_TYPES.ELECTRIC && p.level > 70) ||
      (p.type === POKEMON_TYPES.FIRE && p.level < 10)
    );
  })
);

// REACT

const App = ({ pokemon }) => (
  <div>
    <h2>Vanilla React</h2>
    {pokemon
      .filter(p => {
        return (
          (p.type === POKEMON_TYPES.ELECTRIC ||
            p.type === POKEMON_TYPES.FIRE) &&
          (p.level > 70 || p.level < 10)
        );
      })
      .map(p => {
        return <div key={p.name}>{p.name}</div>;
      })}
  </div>
);

ReactDOM.render(<App pokemon={pokemon} />, document.getElementById('js-app'));
