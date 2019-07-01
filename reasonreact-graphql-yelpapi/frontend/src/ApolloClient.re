[@bs.val] external yelpApiKey: string = "YELP_API_KEY";

let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink =
  ApolloLinks.createHttpLink(~uri="http://localhost:8080/graphql", ());

let authLink =
  ApolloLinks.createContextLink(() =>
    {
      "headers": {
        "authorization": {j|Bearer $yelpApiKey|j},
      },
    }
  );

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|authLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );
