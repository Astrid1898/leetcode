/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start

#define Min(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    if (m == 0 || n == 0)
        return 0;
    int dp[n];
    dp[0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i] = dp[i - 1] + grid[0][i];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                dp[j] += grid[i][j];
            else
                dp[j] = Min(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1];
}
// @lc code=end
