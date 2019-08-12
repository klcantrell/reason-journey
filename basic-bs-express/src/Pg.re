type client;

[@bs.deriving abstract]
type dbResult = {rows: Js.Json.t};

[@bs.module "pg"] [@bs.new] external _makeClient: string => client = "Client";

let makeClient = (~connectionString) => _makeClient(connectionString);

[@bs.send]
external query: (client, string) => Js.Promise.t(dbResult) = "query";
