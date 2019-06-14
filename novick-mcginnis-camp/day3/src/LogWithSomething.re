module LogWith100 = {
  // how to extend modules
  include Log;

  let greatReceived = i => received(i) ++ "100";
}