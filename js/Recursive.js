const _ = require('lodash');

let arr = (() => {
    let a = [];

    for(let i = 1; i < 1000; i++) {
        a.push(i);
    }

    return a
})()

var map = {};

function populateMap(map, targetNumber) {
    for (let n in arr) {
        if (n < targetNumber) {
            map[n] = n
        } else if (n > targetNumber) {

            return map

        }
    }

    return map
}

function findTarget(arr, targetNumber, numberOfResults) {

    if (_.isEmpty(map)) {
        map = populateMap(map, targetNumber);
    }

    for (let i = 0; i < arr.length; i++) {

        let testNumber = arr[i]

        if ( testNumber >= targetNumber )  { return [] }
        let newTargetNumber = targetNumber  - testNumber;

        if (numberOfResults == 2) {

            if  (map[newTargetNumber] && testNumber !== newTargetNumber)  {
                return [testNumber, newTargetNumber]
            }

        } else {

            let newResults = findTarget(arr, newTargetNumber, numberOfResults - 1)
            if (!_.isEmpty(newResults) && newResults.indexOf(testNumber) === -1) {

               newResults.push(testNumber);
               return newResults;

            }

        }

    }

    return [];
}
console.time("findTarget")
var result = findTarget(arr, 2543, 5)
console.timeEnd("findTarget")

console.log("result %s", JSON.stringify(result));
