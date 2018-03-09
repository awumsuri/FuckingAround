function isPalindrome(str1) {
    str1 = str1.replace(/\W/g, "");
    str1 = str1.toLowerCase();

    let i = 0;
    let k = str1.length - 1;

    for (i; i < str1.length/2; i++) {
        if (str1.charAt(i) != str1.charAt(k)) {
            return false;
        }
        k--;
    }

    return true;
}

function sum(x) {
    if (arguments == 2) {
        return arguments[0] + arguments[1];
    }

    return function(y) {
        return x + y
    };
}

console.log(isPalindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama"))
console.log(sum(3)(2))
var arr1 = "john".split('');
var arr2 = arr1.reverse();
var arr3 = "jones".split('');
arr2.push(arr3);
console.log("array 1: length=" + arr1.length + " last=" + arr1.slice(-1));
console.log("array 2: length=" + arr2.length + " last=" + arr2.slice(-1));
console.log(arr1 === arr2)
