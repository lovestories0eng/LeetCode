/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort((a, b) => a - b)
    let result = []
    let help = (currentTarget, cur, index) => {
        if (currentTarget === 0) {
            // 为了复制值而非复制引用，因此用slice
            result.push(cur.slice())
            return
        }
        for (let i = index; i < candidates.length; i++) {
            if(i > index && candidates[i] === candidates[i- 1]){
              // 前提是数组已经被排序好了
              // 若当前元素和前一个元素相等
              // 则本次循环结束，防止出现重复组合
              // 相同的元素中，只要让一个元素往下递归即可
              continue;
            }
            if (currentTarget - candidates[i] >= 0) {
                cur.push(candidates[i])
                help(currentTarget - candidates[i], cur, i + 1)
                cur.pop()
            }
        }
    }
    help(target, [], 0)
    return result
};