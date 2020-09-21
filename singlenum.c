#include <stdio.h>
#include <stdlib.h>

int singleNumber4(int *nums, int numsSize)
{
    int last1 = 0, last2 = 0, output = 0, last3 = 0;
    for (int i = 0; i < numsSize; i++) {
        output = (nums[i] & ~(last1 | last2 | last3)) | (~nums[i] & last1);
        last3 = (last2 & nums[i]) | (last3 & ~nums[i]);
        last2 = (last1 & nums[i]) | (last2 & ~nums[i]);
        last1 = (output & nums[i]) | (last1 & ~nums[i]);
    }
    return output;
}

int singleNumber(int *nums, int numsSize)
{
    int last1 = 0, last2 = 0, output = 0;
    for (int i = 0; i < numsSize; i++) {
        output = (nums[i] & ~(last1 | last2)) | (~nums[i] & last1);
        last2 = (last1 & nums[i]) | (last2 & ~nums[i]);
        last1 = (output & nums[i]) | (last1 & ~nums[i]);
    }
    return output;
}

int main() {
    int nums[10] = {1, 2, 3, 3, 2, 2, 3, 3, 2}, output;

    output = singleNumber4(nums, 9);
    printf("ANS: %d\n", output);
    int nums1[10] = {1, 2, 3, 2, 2, 1, 1};
    output = singleNumber(nums1, 7);
    printf("ANS: %d\n", output);
    return 0;
}
