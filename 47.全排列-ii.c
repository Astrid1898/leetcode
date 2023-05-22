/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **ans;
int **freq;
int freqSize;
int *combine;
int combineSize;

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

int cmpfun(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int *nums, int numsSize, int *returnSize)
{
    if (combineSize == numsSize)
    {
        int *tmp = malloc(sizeof(int) * numsSize);
        memcpy(tmp, combine, sizeof(int) * numsSize);
        ans[(*returnSize)++] = tmp;
    }
    for (int i = 0; i < freqSize; i++)
    {
        if (freq[i][1] < 1)
            continue;
        freq[i][1]--;
        combine[combineSize++] = freq[i][0];
        dfs(nums, numsSize, returnSize);
        combineSize--;
        freq[i][1]++;
    }
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize == 0)
        return NULL;
    qsort(nums, numsSize, sizeof(int), cmpfun);
    freq = malloc(sizeof(int *) * 8);
    freqSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            freq[freqSize] = malloc(sizeof(int) * 2);
            freq[freqSize][0] = nums[i];
            freq[freqSize++][1] = 1;
        }
        else
        {
            freq[freqSize - 1][1]++;
        }
    }
    int maxSize = factor(numsSize);
    ans = malloc(sizeof(int *) * maxSize);
    combine = malloc(sizeof(int) * numsSize);
    combineSize = 0;
    dfs(nums, numsSize, returnSize);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
        (*returnColumnSizes)[i] = numsSize;
    free(combine);
    return ans;
}
// @lc code=end
