const path = require('path');

module.exports = {
  mode: 'development',
  entry: './src/FetchInReason.bs.js',
  devServer: {
    contentBase: path.join(__dirname, 'dist'),
  },
  output: {
    filename: 'main.js',
    path: path.resolve(__dirname, 'dist'),
  },
};
