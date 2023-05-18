/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int ansSize;
int combineSize;
int *ansColumnSize;
int candidatesSize_tmp;

int cmpfun(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int *candidates, int target, int **ansArray, int *combine, int idx)
{
    if (idx == candidatesSize_tmp)
        return;
    if (target == 0)
    {
        int *tmp = malloc(sizeof(int) * combineSize);
        for (int i = 0; i < combineSize; i++)
            tmp[i] = combine[i];
        ansArray[ansSize] = tmp;
        ansColumnSize[ansSize++] = combineSize;
        return;
    }
    dfs(candidates, target, ansArray, combine, idx + 1);
    if (target - candidates[idx] >= 0)
    {
        combine[combineSize++] = candidates[idx];
        dfs(candidates, target - candidates[idx], ansArray, combine, idx);
        combineSize--;
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), cmpfun);
    if (target < candidates[0])
    {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }
    int **ansArray = malloc(sizeof(int *) * 1001);
    ansColumnSize = malloc(sizeof(int) * 1001);
    int combine[2001];
    candidatesSize_tmp = candidatesSize;
    ansSize = combineSize = 0;
    dfs(candidates, target, ansArray, combine, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ansArray;
}
// @lc code=end
