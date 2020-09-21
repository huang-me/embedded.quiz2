#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize)
{
    int lower = 0, higher = 0;
    for (int i = 0; i < numsSize; i++) {
        printf("input: %x%x%x%x\n", (nums[i] >> 3) & 1, (nums[i] >> 2) & 1,
               (nums[i] >> 1) & 1, nums[i] & 1);
        lower ^= nums[i];
        printf("%x%x%x%x, %x%x%x%x\n", (lower >> 3) & 0x01, (lower >> 2) & 0x01,
               (lower >> 1) & 0x01, (lower) &0x01, (higher >> 3) & 0x01,
               (higher >> 2) & 0x01, (higher >> 1) & 0x01, (higher) &0x01);
        lower &= ~higher;
        printf("%x%x%x%x, %x%x%x%x\n", (lower >> 3) & 0x01, (lower >> 2) & 0x01,
               (lower >> 1) & 0x01, (lower) &0x01, (higher >> 3) & 0x01,
               (higher >> 2) & 0x01, (higher >> 1) & 0x01, (higher) &0x01);
        higher ^= nums[i];
        printf("%x%x%x%x, %x%x%x%x\n", (lower >> 3) & 0x01, (lower >> 2) & 0x01,
               (lower >> 1) & 0x01, (lower) &0x01, (higher >> 3) & 0x01,
               (higher >> 2) & 0x01, (higher >> 1) & 0x01, (higher) &0x01);
        higher &= ~lower;
        printf("%x%x%x%x, %x%x%x%x\n", (lower >> 3) & 0x01, (lower >> 2) & 0x01,
               (lower >> 1) & 0x01, (lower) &0x01, (higher >> 3) & 0x01,
               (higher >> 2) & 0x01, (higher >> 1) & 0x01, (higher) &0x01);
        printf("lower: %x, higher: %x\n", lower, higher);
    }
    return lower;
} 

int main() {
    int nums[10] = {4, 4, 4, 5, 5}, output;

    output = singleNumber(nums, 5);
    printf("ANS: %d\n", output);
    return 0;
}
