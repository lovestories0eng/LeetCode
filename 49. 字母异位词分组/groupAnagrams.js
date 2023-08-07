/**
 * @param {string[]} strs
 * @return {string[][]}
*/

var groupAnagrams = function(strs) {
    let map = new Map()

    for (let i = 0; i < strs.length; i++) {
        let tmpStr = [...strs[i]].sort().toString()
        if (map.has(tmpStr)) {
            map.get(tmpStr).push(strs[i])
        } else {
            let set = []
            map.set(tmpStr, set)
            map.get(tmpStr).push(strs[i])
        }
    }

    return Array.from(map.values())
};

let strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
console.log(groupAnagrams(strs))