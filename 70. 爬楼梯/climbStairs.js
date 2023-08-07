/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
  let arr = new Array(n + 1);
  arr[0] = arr[1] = 1;
  for (let i = 1; i < n; i++) {
    arr[i + 1] = arr[i] + arr[i - 1];
  }
  return arr[n];
};
