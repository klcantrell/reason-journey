const express = require('express');
const cors = require('cors');
const request = require('request');

const app = express();
const yelpApi = 'https://api.yelp.com/v3/graphql';

app.use(cors());

app.use(express.json());

app.use('/graphql', (req, res) => {
  request
    .post(yelpApi, {
      json: true,
      body: req.body,
      headers: {
        authorization: req.headers.authorization,
        'content-type': 'application/json',
      },
    })
    .pipe(res);
});

app.listen(8080, () => {
  console.log('Yelp proxy listening on port 8080');
});
