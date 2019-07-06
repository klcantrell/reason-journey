let str = ReasonReact.string;

type restaurantInfo = {
  name: string,
  url: string,
};

module RestaurantCard = {
  [@react.component]
  let make = (~info) => {
    <div className="restaurant-card">
      <p> {str(info.name)} </p>
      <img src={info.url} />
    </div>;
  };
};

module GetMexicanRestaurant = [%graphql
  {|
  query getMexicanRestaurant($location: String, $term: String, $limit: Int, $offset: Int) {
    search(location: $location, term: $term, limit: $limit, offset: $offset) {
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

[@react.component]
let make = (~searchOffset: int) => {
  let mexicanRestaurantQuery =
    GetMexicanRestaurant.make(
      ~location="indianapolis",
      ~term="mexican",
      ~limit=1,
      ~offset=searchOffset,
      (),
    );

  <GetMexicanRestaurantQuery variables=mexicanRestaurantQuery##variables>
    {({result}) =>
       switch (result) {
       | Loading => <div> {str("Loading...")} </div>
       | Error(error) => <div> {str(error##message)} </div>
       | Data(response) =>
         response##search
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
           )
       }}
  </GetMexicanRestaurantQuery>;
};
