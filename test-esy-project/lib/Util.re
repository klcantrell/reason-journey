let fileChannel = open_in("./cool.css");

let fileStream =
  Stream.from(_ =>
    switch (input_line(fileChannel)) {
    | line => Some(line)
    | exception End_of_file => None
    }
  );

let rules = ref([""]);

fileStream
|> Stream.iter(line => {
     let match = Str.string_match(Str.regexp("\\.[A-Za-z$]+"), line, 0);
     if (match) {
       rules := [Str.matched_string(line), ...rules^];
     };
   });

let rulesStringified =
  rules^
  |> List.fold_left(
       (str, rule) =>
         switch (rule) {
         | "" => rule ++ str
         | _ => "\n" ++ rule ++ str
         },
       "",
     );

let hello = () =>
  Pastel.(
    <Pastel>
      "\n"
      <Pastel color=Red> "Hello" </Pastel>
      ", "
      <Pastel color=Green> Sys.os_type </Pastel>
      "!\n"
      <Pastel color=BlueBright> "Rules in your css modules file:" </Pastel>
      <Pastel color=Yellow> rulesStringified </Pastel>
    </Pastel>
  );