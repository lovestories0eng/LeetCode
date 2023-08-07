// 超时
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */

let combinationSum2 = function (candidates ,  target) {
    // write code here
    let used = new Array(candidates.length)
    let result = []
    // 全部初始化为false代表元素未被访问
    for (let i = 0; i < candidates.length; i++) {
        used[i] = false
    }

    let path = []
    dfs(candidates, used, 0, result, target, path)
    return result
}

function isNotEqual(arr1, arr2) {
  // 如果两个数组相等，则返回 false
  if (arr1.length === arr2.length) {
    return arr1.some((item, index) => item !== arr2[index]);
  }
  // 如果两个数组长度不相等，则返回 true
  return true;
}

function dfs(candidates, used, sum, result, target, path) {
    // 如果和已经大于了target则剪枝，直接return
    if (sum > target) 
        return

    // 如果数组的和 === target
    if (sum === target) {
        let flag = true
        for (let i = 0; i < result.length; i++) {
            flag = flag && isNotEqual(path, result[i])
            if (flag === false) break
        }
        if (flag)
            result.push(Array.from(path))
        return
    }

    for (let i = 0; i < candidates.length; i++) {
        // 如果当前元素没有被访问过
        if (!used[i]) {
            // TODO: 判断是否能够满足升序条件
            if (candidates[i] < path[path.length - 1])
                continue

            // 标记元素已经被访问了
            used[i] = true
            path.push(candidates[i])
            sum += candidates[i]
            // 进行深搜操作
            dfs(candidates, used, sum, result, target, path)
            // 回溯把used置为false
            used[i] = false
            path.pop()
            sum -= candidates[i]
        }
    }
}