/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */

// @lc code=start

int uniquePaths(int m, int n)
{
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y)
    {
        ans = ans * x / y;
    }
    return ans;
}
// @lc code=end
