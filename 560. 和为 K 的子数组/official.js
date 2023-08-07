var subarraySum = function (nums, k) {
  let count = 0;
  for (let left = 0; left <= nums.length - 1; left++) {
    let sum = 0;
    for (let right = left; right <= nums.length - 1; right++) {
      sum += nums[right];
      if (sum === k) {
        count++;
      }
    }
  }

  return count;
};
