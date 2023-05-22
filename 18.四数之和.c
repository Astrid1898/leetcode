/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
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
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 4)
        return NULL;
    qsort(nums, numsSize, sizeof(int), cmpfun);
    int first = 0;
    int **returnArray = (int **)malloc(sizeof(int *) * (numsSize - 3) * (numsSize - 3) * (numsSize - 3));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (numsSize - 3) * (numsSize - 3) * (numsSize - 3));
    for (; first < numsSize - 3; first++)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        for (int second = first + 1; second < numsSize - 2; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            int forth = numsSize - 1;
            int part = nums[first] + nums[second];
            for (int third = second + 1; third < numsSize - 1; third++)
            {
                if (third > second + 1 && nums[third] == nums[third - 1])
                    continue;
                while (third < forth && part + nums[third] + nums[forth] > target)
                {
                    --forth;
                }
                if (third == forth)
                    break;
                if (part + nums[third] + nums[forth] == target)
                {
                    returnArray[*returnSize] = malloc(sizeof(int) * 4);
                    (*returnColumnSizes)[*returnSize] = 4;
                    returnArray[*returnSize][0] = nums[first];
                    returnArray[*returnSize][1] = nums[second];
                    returnArray[*returnSize][2] = nums[third];
                    returnArray[*returnSize][3] = nums[forth];
                    (*returnSize)++;
                }
            }
        }
    }
    return returnArray;
}
// @lc code=end
