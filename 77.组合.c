/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
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
int maxSequenceSize;

void dfs(int idx, int n, int *cnt)
{
    if ((maxSequenceSize - sequenceSize) > (n - idx + 1))
        return;
    if (sequenceSize == maxSequenceSize)
    {
        int *tmp = (int *)malloc(sizeof(int) * maxSequenceSize);
        for (int i = 0; i < maxSequenceSize; i++)
            tmp[i] = sequence[i];
        ans[(*cnt)++] = tmp;
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        sequence[sequenceSize++] = i;
        dfs(i + 1, n, cnt);
        sequenceSize--;
    }
}
int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (n == 0 || k == 0)
        return NULL;
    int maxSize = 1;
    for (int i = 1; i <= k; i++)
        maxSize = maxSize * (n - i + 1) / (i);
    ans = malloc(sizeof(int *) * maxSize);
    *returnColumnSizes = malloc(sizeof(int) * maxSize);
    for (int i = 0; i < maxSize; i++)
        (*returnColumnSizes)[i] = k;
    sequence = malloc(sizeof(int) * k);
    sequenceSize = 0;
    maxSequenceSize = k;
    dfs(1, n, returnSize);
    free(sequence);
    return ans;
}
// @lc code=end
