'use strict';
function hash(str) {
  var i = 0;
  for (var j = 0; j < str.length; ++j)
    i = (i * 223 + str.charCodeAt(j)) & ((1 << 31) - 1);
  return i;
}

function anti_hash(i) {
  var a = 'a'.charCodeAt(0);
  for (var x1 = a; x1 < a+26; ++x1) {
    for (var x2 = a; x2 < a+26; ++x2) {
      for (var x3 = a; x3 < a+26; ++x3) {
        for (var x4 = a; x4 < a+26; ++x4) {
          for (var x5 = a; x5 < a+26; ++x5) {
            var fuck = String.fromCharCode(x1, x2, x3, x4, x5);
            if (i === hash(fuck)){
              console.log(fuck);
            }
          }
        }
      }
    }
  }
}


function testpw(input){
  if (   input.length == 15
      && /^[a-z]*$/.test(input)
      && hash(input.substr(0, 5)) == 51848940
      && hash(input.substr(5, 5)) == 572630241
      && hash(input.substr(10, 5)) == 131805636) {
  alert("Yes! The 5th passcode is: " + input);
  } else if (input.length > 0) {
  alert("No. The 5th passcode is not: " + input);
  } else {
  alert("This button works!");
  }
}

var t = performance.now()
anti_hash(51848940);
anti_hash(572630241);
anti_hash(131805636);
console.log('Time spent: ' + (performance.now() - t) + ' ms')
testpw('madeahashofthis')