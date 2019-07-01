let str = ReasonReact.string;

module GetMexicanRestaurant = [%graphql
  {|
  query getMexicanRestaurant($location: String, $limit: Int, $offset: Int) {
    search(location: $location, limit: $limit, offset: $offset) {
      total
      business {
        name
      }
    }
  }
|}
];

module GetMexicanRestaurantQuery =
  ReasonApollo.CreateQuery(GetMexicanRestaurant);

type actions =
  | GetRandom;

type state = {number: float};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | GetRandom => {number: 0.0}
        },
      {number: 0.0},
    );
  let mexicanRestaurantQuery =
    GetMexicanRestaurant.make(
      ~location="indianapolis",
      ~limit=1,
      ~offset=1,
      (),
    );

  <GetMexicanRestaurantQuery variables=mexicanRestaurantQuery##variables>
    {({result}) =>
       switch (result) {
       | Loading => <div> {str("Loading...")} </div>
       | Error(error) => <div> {str(error##message)} </div>
       | Data(response) =>
         <div>
           {response##search
            ->Belt.Option.flatMap(search => search##business)
            ->Belt.Option.flatMap(businesses => businesses[0])
            ->Belt.Option.flatMap(business => business##name)
            ->Belt.Option.mapWithDefault(React.null, name => str(name))}
         </div>
       }}
  </GetMexicanRestaurantQuery>;
};
