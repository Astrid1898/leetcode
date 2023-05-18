/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfun(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;

    qsort(nums, numsSize, sizeof(int), cmpfun);

    int first = 0;
    int **retrunArray = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);

    for (; first < numsSize; first++)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        int third = numsSize - 1;
        int target = -nums[first];
        for (int second = first + 1; second < numsSize; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            while (second < third && nums[second] + nums[third] > target)
                --third;
            if (third == second)
                break;
            if (nums[second] + nums[third] == target)
            {
                retrunArray[*returnSize] = (int *)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                retrunArray[*returnSize][0] = nums[first];
                retrunArray[*returnSize][1] = nums[second];
                retrunArray[*returnSize][2] = nums[third];
                (*returnSize)++;
            }
        }
    }
    return retrunArray;
}

// @lc code=end
