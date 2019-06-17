let url = "https://jsonplaceholder.typicode.com/posts/";

[@bs.deriving { jsConverter: newType }]
type post = {
  userId: int,
  title: string,
  body: string,
};

module Decode = {
  let post = post =>
    Json.Decode.{
      userId: field("userId", int, post),
      title: field("title", string, post),
      body: field("body", string, post),
    };
};

let fetchPost = postId =>
  Js.Promise.(
    Fetch.fetch(url ++ string_of_int(postId))
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode.post |> (post => Some(post) |> resolve))
  );

Js.Promise.(
  fetchPost(3)
  |> then_(
    fun
    | Some(post) => resolve(Js.log(postToJs(post)))
    | None => resolve(Js.log("null"))
  )
);
