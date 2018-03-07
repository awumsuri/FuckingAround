let count = 0;

function FibR(n) {

  count ++;

  if ( n == 0 )
    return 0;

  if (n == 1)
    return 1;

  if ( n > 1)
    return FibR(n - 1) + FibR(n - 2);

}

function FibI(n) {

  count = 0;

  let fib_minus_one = 1;
  let fib_minus_two = 0;
  let FibN = 0;

  if ( n === 0 ) {
    return 0;
  }

  if ( n === 1 ) {
    return 1;
  }

  for (let i = 2; i <= n; i++ ) {

    count ++;
    FibN = fib_minus_one + fib_minus_two;
    fib_minus_two = fib_minus_one;
    fib_minus_one = FibN;

  }

  return FibN;
}

function s() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {console.log("In settimeout"); resolve()}, 1000);
  });

}

s().then(() => {
  console.log("Done");
})
//console.log("Fib:%s Count:%s",FibR(40), count);
//console.log("FibI:%s Count:%s",FibI(100), count);

