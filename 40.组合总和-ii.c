/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *ansColunmSize;
int *combine;
int **freq;
int combineSize;
int freqSize = 0;
int **ansArray;

void dfs(int *candidates, int candidatesSize, int target, int *returnSize, int index)
{
    if (target == 0)
    {
        int *tmp = malloc(sizeof(int) * combineSize);
        memcpy(tmp, combine, sizeof(int) * combineSize);
        ansArray[*returnSize] = tmp;
        ansColunmSize[(*returnSize)++] = combineSize;
        return;
    }
    if (index == freqSize || target < freq[index][0])
    {
        return;
    }
    dfs(candidates, candidatesSize, target, returnSize, index + 1);
    int most = fmin(target / freq[index][0], freq[index][1]);
    for (int i = 1; i <= most; i++)
    {
        combine[combineSize++] = freq[index][0];
        dfs(candidates, candidatesSize, target - i * freq[index][0], returnSize, index + 1);
    }
    combineSize -= most;
}
int cmpfun(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmpfun);
    if (target < candidates[0])
    {
        returnColumnSizes = NULL;
        return NULL;
    }
    ansArray = malloc(sizeof(int *) * 2001);
    ansColunmSize = malloc(sizeof(int) * 2001);
    combine = malloc(sizeof(int) * 2001);
    freq = malloc(sizeof(int *) * 2001);
    freqSize = combineSize = 0;
    for (int i = 0; i < candidatesSize; i++)
    {
        if (i == 0 || candidates[i] != candidates[i - 1])
        {
            freq[freqSize] = malloc(sizeof(int) * 2);
            freq[freqSize][0] = candidates[i];
            freq[freqSize++][1] = 1;
        }
        else
        {
            freq[freqSize - 1][1]++;
        }
    }
    dfs(candidates, candidatesSize, target, returnSize, 0);
    *returnColumnSizes = ansColunmSize;
    return ansArray;
}
// @lc code=end
