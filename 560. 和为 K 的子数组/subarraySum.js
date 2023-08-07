/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
// 这里只考虑了数组全为正数的情况
var subarraySum = function (nums, k) {
  let count = 0;
  let left = (right = 0);
  let sum = nums[0];
  while (right <= nums.length - 1) {
    if (sum < k) {
      right++;
      sum += nums[right];
    } else {
      if (sum === k) {
        count++;
      }
      sum -= nums[left];
      if (left === right) {
        right++;
      }
      left++;
    }
  }

  return count;
};

console.log(subarraySum([1, 1, 1], 2));
console.log(subarraySum([1, 2, 3], 3));
