const path = require('path');

module.exports = {
  mode: 'development',
  entry: {
    app: './src/Main.bs.js',
  },
  devServer: {
    contentBase: path.join(__dirname, 'dist'),
  },
  output: {
    filename: '[name].bundle.js',
    path: path.resolve(__dirname, 'dist'),
  },
  module: {
    rules: [
      {
        test: /\.m?js$/,
        exclude: /(node_modules|bower_components)/,
        use: {
          loader: 'babel-loader',
          options: {
            presets: ['@babel/preset-env', '@babel/preset-react'],
          },
        },
      },
    ],
  },
};
