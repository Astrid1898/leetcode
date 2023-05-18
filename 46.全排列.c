/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *combine;
int combineSize;
int **ans;
bool *isUsed;

int factor(int n)
{
    int ans = 1;
    if (n == 0)
        return ans;
    else
    {
        for (int i = 1; i <= n; i++)
            ans = ans * i;
    }
    return ans;
}

void dfs(int *nums, int numSize, int *returnSize)
{
    if (numSize == combineSize)
    {
        int *tmp = malloc(sizeof(int) * numSize);
        for (int i = 0; i < numSize; i++)
        {
            tmp[i] = combine[i];
        }
        ans[(*returnSize)++] = tmp;
        return;
    }
    for (int i = 0; i < numSize; i++)
    {
        if (isUsed[i])
            continue;
        isUsed[i] = true;
        combine[combineSize++] = nums[i];
        dfs(nums, numSize, returnSize);
        combineSize--;
        isUsed[i] = false;
    }
}
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize == 0)
        return NULL;
    int total = factor(numsSize);
    combine = malloc(sizeof(int) * numsSize);
    ans = malloc(sizeof(int *) * total);
    combineSize = 0;
    isUsed = malloc(sizeof(bool) * numsSize);
    memset(isUsed, 0, sizeof(bool) * numsSize);
    dfs(nums, numsSize, returnSize);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
        (*returnColumnSizes)[i] = numsSize;
    free(combine);
    return ans;
}
// @lc code=end
