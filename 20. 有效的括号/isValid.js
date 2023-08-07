/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  for (let c of s) {
    if (c === "(" || c === "{" || c === "[") {
      stack.push(c);
    } else if (c === ")") {
      let tmp = stack[stack.length - 1];
      if (tmp === "(") {
        stack.pop();
      } else return false;
    } else if (c === "]") {
      let tmp = stack[stack.length - 1];
      if (tmp === "[") {
        stack.pop();
      } else return false;
    } else if (c === "}") {
      let tmp = stack[stack.length - 1];
      if (tmp === "{") {
        stack.pop();
      } else return false;
    }
  }
  return stack.length === 0;
};

console.log(isValid("()[]{}"));
