let str = ReasonReact.string;

type restaurantInfo = {
  name: string,
  url: string,
};

module RestaurantCard = {
  [@react.component]
  let make = (~info) => {
    <div> <p> {str(info.name)} </p> <img src={info.url} /> </div>;
  };
};

module GetMexicanRestaurant = [%graphql
  {|
  query getMexicanRestaurant($location: String, $limit: Int, $offset: Int) {
    search(location: $location, limit: $limit, offset: $offset) {
      total
      business {
        name
        photos
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
            ->Belt.Option.mapWithDefault(
                React.null,
                business => {
                  let businessName =
                    business##name->Belt.Option.getWithDefault("");
                  let firstPhoto =
                    business##photos
                    ->Belt.Option.getWithDefault([||])
                    ->(photos => photos[0]->Belt.Option.getWithDefault(""));
                  let info = {name: businessName, url: firstPhoto};
                  <RestaurantCard info />;
                },
              )}
         </div>
       }}
  </GetMexicanRestaurantQuery>;
};
