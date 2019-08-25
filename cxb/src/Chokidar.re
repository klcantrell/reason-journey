type chokidar;
type fileWatcher;
type watchHandler = string => unit;

[@bs.module] external chokidar: chokidar = "chokidar";

[@bs.send] external watch_: (chokidar, string) => fileWatcher = "watch";

[@bs.send] external on_: (fileWatcher, string, watchHandler) => unit = "on";

let makeWatcher = pattern => watch_(chokidar, pattern);

let onChange = (watchHandler, watcher) =>
  on_(watcher, "change", watchHandler);
