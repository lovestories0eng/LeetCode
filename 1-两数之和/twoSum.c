#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int)*2);
    for(int i=0;i < numsSize;i++) {
        int difference = target - nums[i];
        for(int j=0;j < numsSize;j++) {
            if (i == j) break;
            if (nums[j] == difference) {
                result[0] = i;
                result[1] = j;
            }
            
        }
    }
    return result;
}

int main() {
    return 0;
}