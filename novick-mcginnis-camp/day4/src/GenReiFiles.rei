let myName: string;
let conditionallyAssignThis: string;
let testBinding: string;
let lastExpressionIsReturned: string;
let myFirstTuple: (string, int);
let tupVal1: string;
let tupVal2: int;
let onlyWantTup2: int;
type person = { name: string, age: int, };
let whoAmI: person;
type rocket = {
  rocketType: string,
  mutable destination: string,
  fuelType: string,
};
type rocketDestination('a) = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates('a),
}
and celestialCoordinates('a) = { ra: ('a, 'a, 'a), dec: ('a, 'a, 'a), };
let rocketToMars: rocket;
let marsDestination: rocketDestination(string);
type myFirstVariant = This | That;
type point = Point(float, float);
let myPointInstance: point;
type shape = Rectangle(point, point) | Circle(point, float);
type usingOptionalType = { name: option(string), };
let me: usingOptionalType;
type myRecord = { myField: (string, string), };
let myRecordInstance: myRecord;
let greeting: string;
let myTuple: (int, int);
let isKal: string => bool;
let result: string;
let exchange: int => int;
