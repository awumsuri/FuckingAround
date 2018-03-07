let arr = (() => {
    let a = [];

    for(let i = 1; i < 100000; i++) {
        a.push(i);
    }

    return a
})()

//let arr = [1,2,3,4,5,6,7,8]

function findTarget(arr, targetNumber) {

    var map= {};

    for (n in arr) {
        map[n] = n
    }

    for (let i = 0; i < arr.length; i++) {

        let testNumber = arr[i]

        if ( testNumber >= targetNumber )  { return {} }
        let numberToAdd = targetNumber  - testNumber;

        if  (map[numberToAdd])  {
            return {
                "firstNumber": testNumber,
                "secondNumber": numberToAdd
            }
        }

    }

    return {};
}
console.time("findTarget")
var result = findTarget(arr, 2000)
console.timeEnd("findTarget")

console.log("Call to doSomething took result:" + JSON.stringify(result))
