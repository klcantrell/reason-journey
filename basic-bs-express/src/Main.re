open Express;

let app = express();

let connectionString = "postgresql://postgres:[password]@localhost:5432/ig_clone";

let client = Pg.makeClient(~connectionString);
client->Pg.connect;

App.get(app, ~path="/") @@
PromiseMiddleware.from((_, _, res) =>
  Js.Promise.(
    client->Pg.query("select version()")
    |> then_(data => {
         Js.log(data->Pg.rowsGet);
         resolve(data->Pg.rowsGet);
       })
    |> then_(value => {
         client->Pg.endConnection;
         res |> Response.sendString(value) |> resolve;
       })
    |> catch(err => {
         Js.log(err);
         res |> Response.sendString("damn it") |> resolve;
       })
  )
);

App.get(app, ~path="/error-test") @@
Middleware.from((_, _) =>
  try (Js.Exn.raiseError("YIKES")) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.stack(e)) {
    | Some(trace) => Response.sendString({j|Error: $trace|j})
    | None => Response.sendString("An unknown error occurred")
    }
  }
);

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

App.listen(app, ~port=3000, ~onListen, ());
