// The word eval cannot be used as a variable:

"use strict";

// let value = 3;
// console.log(value);

// The word arguments cannot be used as a variable:

// function test(a, b) {
//   console.log(arguments)
// }
// test(1, 3)

// The with statement is not allowed:

// let x = Math.cos(2);
// console.log(object)
const {cos} = Math;
let x = cos(23);
console.log(x)