/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let maxValue = 0
    for (let i = 0; i < height.length; i++) {
        for (let j = i + 1; j < height.length; j++) {
            let minHeight = Math.min(height[i], height[j])
            
        }
    }
};