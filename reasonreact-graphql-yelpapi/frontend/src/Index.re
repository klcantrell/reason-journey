[@bs.module] external styles: unit = "./main.css";

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=ApolloClient.instance>
    <App />
  </ReasonApollo.Provider>,
  "app",
);
