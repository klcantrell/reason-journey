Js.log(
  Knode.Fs.(writeFileSync(. "hi.txt", "myDude", "utf8", err => Js.log(err))),
);
