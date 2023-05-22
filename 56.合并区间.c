/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a, b) ((a) > (b) ? (a) : (b))

int cmpfun(const void **a, const void **b)
{
    return *(*(int **)a + 0) - *(*(int **)b + 0);
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (intervalsSize == 0)
        return NULL;
    qsort(intervals, intervalsSize, sizeof(int *), cmpfun);
    int **ans;
    *returnSize = 0;
    ans = malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    int thisInterval[2] = {intervals[0][0], intervals[0][1]};
    for (int i = 0; i < intervalsSize; i++)
    {
        if (intervals[i][0] <= thisInterval[1])
        {
            thisInterval[1] = max(intervals[i][1], thisInterval[1]);
            continue;
        }
        else
        {
            ans[*returnSize] = malloc(sizeof(int) * 2);
            ans[*returnSize][0] = thisInterval[0];
            ans[*returnSize][1] = thisInterval[1];
            (*returnColumnSizes)[*returnSize] = 2;
            thisInterval[0] = intervals[i][0];
            thisInterval[1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    ans[*returnSize] = malloc(sizeof(int) * 2);
    ans[*returnSize][0] = thisInterval[0];
    ans[*returnSize][1] = thisInterval[1];
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;
    return ans;
}
// @lc code=end
