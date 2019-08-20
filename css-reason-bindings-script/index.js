const fs = require('fs');
const path = require('path');
const chokidar = require('chokidar');
const css = require('css');

chokidar.watch('**/*.css').on('change', (path_, event) => {
  const changedCss = fs.readFileSync(path.resolve(path_), 'utf8');
  try {
    const ast = css.parse(changedCss.toString());
    const rules = ast.stylesheet.rules.map(rule => rule.selectors[0]);
    rules.length > 0 && makeReasonBindings(path_, rules);
  } catch (e) {
    console.error(`Something went wrong parsing css:  ${e.reason} in ${path_}`);
  }
});

const makeReasonBindings = (path, rules) => {
  console.log(makeFilename(path));
  console.log(rules);
};

const makeFilename = path => {
  const fragments = path.split('\\');
  const filename = fragments[fragments.length - 1].split('.')[0];
  return filename.charAt(0).toUpperCase() + filename.slice(1) + 'Styles.re';
};
