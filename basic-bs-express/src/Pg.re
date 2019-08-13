type client;

[@bs.deriving abstract]
type dbResult = {rows: string};

[@bs.module "pg"] [@bs.new] external _makeClient: string => client = "Client";

let makeClient = (~connectionString) => _makeClient(connectionString);

[@bs.send]
external query: (client, string) => Js.Promise.t(dbResult) = "query";

[@bs.send] external connect: client => unit = "connect";

[@bs.send] external endConnection: client => unit = "end";
