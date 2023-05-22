/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 */

// @lc code=start

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    bool fistColumn = false;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize[0]; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j == 0)
                    fistColumn = true;
                else
                    matrix[0][j] = 0;
            }
        }
    }
    for (int j = 1; j < matrixColSize[0]; j++)
    {
        if (matrix[0][j] == 0)
            for (int i = 1; i < matrixSize; i++)
                matrix[i][j] = 0;
    }
    for (int i = 1; i < matrixSize; i++)
    {
        if (matrix[i][0] == 0)
            for (int j = 1; j < matrixColSize[0]; j++)
            {
                matrix[i][j] = 0;
            }
    }
    if (matrix[0][0] == 0)
        for (int i = 0; i < matrixColSize[0]; i++)
            matrix[0][i] = 0;
    if (fistColumn)
        for (int i = 0; i < matrixSize; i++)
            matrix[i][0] = 0;
}

// @lc code=end
