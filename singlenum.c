#include <stdio.h>
#include <stdlib.h>

int singleNumber5(int *nums, int numsSize)
{
    int last1 = 0, last2 = 0, output = 0, last3 = 0, last4 = 0;
    for (int i = 0; i < numsSize; i++) {
        output =
            (nums[i] & ~(last1 | last2 | last3 | last4)) | (~nums[i] & last1);
        last4 = (last3 & nums[i]) | (last4 & ~nums[i]);
        last3 = (last2 & nums[i]) | (last3 & ~nums[i]);
        last2 = (last1 & nums[i]) | (last2 & ~nums[i]);
        last1 = (output & nums[i]) | (last1 & ~nums[i]);
    }
    return output;
}

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

    int nums1[10] = {1, 1, 1, 2, 1, 1};
    output = singleNumber5(nums1, 6);
    printf("ANS of 5 times: %d\n", output);
    output = singleNumber4(nums, 9);
    printf("ANS of 4 times: %d\n", output);
    int nums2[10] = {1, 2, 3, 2, 2, 1, 1};
    output = singleNumber(nums2, 7);
    printf("ANS of 3 times: %d\n", output);
    return 0;
}
