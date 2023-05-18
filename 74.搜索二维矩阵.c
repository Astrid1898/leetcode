/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return false;
    if (target < matrix[0][0] || target > matrix[matrixSize - 1][matrixColSize[0] - 1])
        return false;
    int colunm = -1;
    int left = 0, right = matrixSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == matrix[mid][0])
            return true;
        else if (target > matrix[mid][0])
        {
            left = mid + 1;
            colunm = mid;
        }
        else
        {
            right = mid - 1;
            colunm = right;
        }
    }
    left = 0;
    right = matrixColSize[0] - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == matrix[colunm][mid])
            return true;
        else if (target > matrix[colunm][mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
// @lc code=end
