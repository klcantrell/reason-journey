// Log.make(); not exposed by interface file

Js.log(Log.received(1));

Js.log(LogWithSomething.LogWith100.greatReceived(2));

// how to alias modules
module L = Log;

L.print(32);