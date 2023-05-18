/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int f[obstacleGridColSize[0]];
    memset(f, 0, sizeof(f));
    f[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < obstacleGridColSize[0]; j++)
        {
            if (obstacleGrid[i][j])
            {
                f[j] = 0;
                continue;
            }
            if (j - 1 >= 0)
            {
                f[j] += f[j - 1];
            }
        }
    }
    return f[obstacleGridColSize[0] - 1];
}
// @lc code=end
