/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if (nums.length === 0) return 0
    nums.sort((a, b) => a - b)
    let maxLength = 0, same = 0
    let isContinuous = (prev, next) => {
        let tmpFlag = false
        if (next - prev === 0) {
            tmpFlag = true
        }
        // 记录相同数的个数
        tmpFlag && same++
        // (next  - prev === 1) or (next - prev === 0)
        return (next - prev) === 1 || tmpFlag
    }
    let leftPtr = rightPtr = 0
    while (rightPtr < nums.length - 1) {
        if (isContinuous(nums[rightPtr], nums[rightPtr + 1])) {
            rightPtr++
        } else {
            let length = rightPtr - leftPtr + 1 - same
            same = 0
            length > maxLength && (maxLength = length)
            leftPtr = rightPtr = rightPtr + 1
        }
    }
    let length = rightPtr - leftPtr + 1 - same
    length > maxLength && (maxLength = length)
    return maxLength
};