open Express;

let app = express();

App.get(app, ~path="/") @@
Middleware.from((_, _) => Response.sendString("Hello bs-express"));

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

App.listen(app, ~port=3000, ~onListen, ());
