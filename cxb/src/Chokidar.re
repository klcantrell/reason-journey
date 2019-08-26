type fileWatcher;
type watchHandler = string => unit;

[@bs.module "chokidar"] [@bs.val]
external makeWatcher: string => fileWatcher = "watch";

[@bs.send] external on_: (fileWatcher, string, watchHandler) => unit = "on";

let onChange = (watchHandler, watcher) =>
  on_(watcher, "change", watchHandler);
