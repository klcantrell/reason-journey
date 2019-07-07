let str = ReasonReact.string;

type restaurantInfo = {
  name: string,
  url: string,
};

module RestaurantCard = {
  [@react.component]
  let make = (~info: restaurantInfo, ~onExitClick: unit => unit) => {
    <div className="restaurant-card">
      <i onClick={e => onExitClick()}> {str("X")} </i>
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
let make = (~searchOffset: int, ~onExitClick: unit => unit) => {
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
       | Loading =>
         <div className="restaurant-card"> <p> {str("Loading...")} </p> </div>
       | Error(error) =>
         <div className="restaurant-card">
           <p> {str(error##message)} </p>
         </div>
       | Data(response) =>
         Belt.Option.(
           response##search
           ->flatMap(search => search##business)
           ->flatMap(businesses => businesses[0])
           ->mapWithDefault(
               React.null,
               business => {
                 let businessName = business##name->getWithDefault("");
                 let firstPhoto =
                   business##photos
                   ->getWithDefault([||])
                   ->(photos => photos[0]->getWithDefault(""));
                 let info = {name: businessName, url: firstPhoto};
                 <RestaurantCard info onExitClick />;
               },
             )
         )
       }}
  </GetMexicanRestaurantQuery>;
};
