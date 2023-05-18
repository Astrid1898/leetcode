/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **ans = malloc(sizeof(int *) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    int target = n * n, num = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int left = 0, right = n - 1, up = 0, down = n - 1;
    while (num <= target)
    {
        for (int i = left; i <= right; i++)
            ans[up][i] = num++;
        up++;
        for (int i = up; i <= down; i++)
            ans[i][right] = num++;
        right--;
        for (int i = right; i >= left; i--)
            ans[down][i] = num++;
        down--;
        for (int i = down; i >= up; i--)
            ans[i][left] = num++;
        left++;
    }
    return ans;
}
// @lc code=end
