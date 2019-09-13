let files =
  Sys.readdir(".")
  |> Array.fold_left((acc, file) => acc ++ file ++ "\n", "");

let hello = () =>
  Pastel.(
    <Pastel>
      <Pastel color=Red> "Hello" </Pastel>
      ", "
      <Pastel color=Green> Sys.os_type </Pastel>
      "!\n"
      <Pastel color=BlueBright> "Files in your directory:\n" </Pastel>
      <Pastel color=Yellow> files </Pastel>
    </Pastel>
  );