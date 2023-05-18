/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **ans;
int *sequence;
int sequenceSize;
int *ansSize;

void dfs(int *nums, int idx, int maxLen, int *cnt, int numSize)
{
    if (maxLen - sequenceSize > numSize - idx)
        return;
    if (sequenceSize == maxLen)
    {
        int *tmp = malloc(sizeof(int) * maxLen);
        for (int i = 0; i < maxLen; i++)
            tmp[i] = sequence[i];
        ans[(*cnt)] = tmp;
        ansSize[(*cnt)++] = maxLen;
        return;
    }
    for (int i = idx; i < numSize; i++)
    {
        sequence[sequenceSize++] = nums[i];
        dfs(nums, i + 1, maxLen, cnt, numSize);
        sequenceSize--;
    }
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int maxSize = 1 << numsSize;
    ans = (int **)malloc(sizeof(int *) * maxSize);
    ansSize = (int *)malloc(sizeof(int) * maxSize);
    sequence = malloc(sizeof(int) * numsSize);
    sequenceSize = 0;
    for (int i = 0; i <= numsSize; i++)
    {
        dfs(nums, 0, i, returnSize, numsSize);
    }
    *returnColumnSizes = ansSize;
    return ans;
    free(sequence);
}
// @lc code=end
