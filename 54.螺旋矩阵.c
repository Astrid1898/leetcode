/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    *returnSize = 0;
    if (matrixSize == 0 || matrixColSize == 0)
        return NULL;
    int rows = matrixSize, columns = matrixColSize[0];
    int total = rows * columns;
    int *ans = malloc(sizeof(int) * total);
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    while (left <= right && top <= bottom)
    {
        for (int column = left; column <= right; column++)
        {
            ans[(*returnSize)++] = matrix[top][column];
        }
        for (int row = top + 1; row <= bottom; row++)
        {
            ans[(*returnSize)++] = matrix[row][right];
        }
        if (left < right && top < bottom)
        {
            for (int column = right - 1; column > left; column--)
            {
                ans[(*returnSize)++] = matrix[bottom][column];
            }
            for (int row = bottom; row > top; row--)
            {
                ans[(*returnSize)++] = matrix[row][left];
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return ans;
}
// @lc code=end
