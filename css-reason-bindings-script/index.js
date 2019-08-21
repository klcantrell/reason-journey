#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const chokidar = require('chokidar');
const css = require('css');

const argv = require('minimist')(process.argv.slice(2), {
  string: 'path',
  boolean: 'help',
  alias: {
    p: 'path',
    h: 'help',
  },
  default: {
    path: '.',
    help: false,
  },
  unknown: unknownArg => {
    console.log(
      `Sorry, ${unknownArg} is an unrecognized argument!  Please try again.`
    );
    process.exit(1);
  },
});

if (argv.help) {
  console.log(`
    Use the --path (alias -p) argument to specify a path to watch your css files

    Example:
    cmb --path styles

    The above example will watch the styles directory of your project
  `);
  process.exit(0);
}

const pathArg = path.resolve(argv.path);

if (!fs.existsSync(pathArg)) {
  console.log(`Sorry, the path ${pathArg} does not exist!  Please try again.`);
  process.exit(1);
}

process.chdir(pathArg);

console.log(`Listening for css changes in ${pathArg}`);

chokidar.watch('**/*.css').on('change', (path_, event) => {
  console.log(`Detected change in ${path_}`);
  const changedCss = fs.readFileSync(path.resolve(path_), 'utf8');
  try {
    const ast = css.parse(changedCss.toString());
    const rules = ast.stylesheet.rules.map(rule => rule.selectors[0]);
    rules.length > 0 && makeReasonBindings(path_, rules);
  } catch (e) {
    console.error(`Something went wrong parsing css:  ${e.reason} in ${path_}`);
  }
});

const makeReasonBindings = (path_, rules) => {
  const filename = makeFilename(path_);
  const precedingPath = extractPrecedingPath(path_);
  const ruleTypes = makeRuleTypes(rules);
  const content = makeContent(ruleTypes);
  const newFilePath = precedingPath
    ? precedingPath + '\\' + filename
    : filename;

  console.log(`Creating file ${filename}...`);

  writeFile(path.join(newFilePath), content);
};

const makeFilename = path => {
  const fragments = path.split('\\');
  const filename = fragments[fragments.length - 1].split('.')[0];
  return (
    filename.charAt(0).toUpperCase() +
    filename.slice(1).toLowerCase() +
    'Styles.re'
  );
};

const makeRuleTypes = rules =>
  rules
    .map(rule => `${rule.slice(1)}: Js.Nullable.t(string),`)
    .reduce((str, rule) => str + '\n\t\t' + rule);

const makeContent = ruleTypes => {
  return ` // GENERATED CONTENT - PLEASE DO NOT EDIT
  [@bs.deriving {abstract: light}]
  type t = {
    ${ruleTypes}
  };
`;
};

const extractPrecedingPath = path => {
  const fragments = path.split('\\');
  return fragments.length === 1 ? '' : fragments.slice(0, fragments.length - 1);
};

const writeFile = (path, content) => {
  fs.writeFileSync(path, content, 'utf8', err => {
    if (err) throw err;
  });
  console.log('File created');
};
