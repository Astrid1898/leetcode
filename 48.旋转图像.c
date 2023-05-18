/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 */

// @lc code=start
void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    for (int i = 0; i < matrixSize / 2; i++)
    {
        for (int j = 0; j < (matrixSize + 1) / 2; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = tmp;
        }
    }
}
// @lc code=end
