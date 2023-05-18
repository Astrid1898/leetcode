/*
 * @Descripttion: 
 * @version: 
 * @Author: Zhao Jiangfeng
 * @Date: 2021-05-16 21:49:20
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2021-05-16 23:04:40
 */
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    left[i][j] = (j == 0 ? 1 : left[i][j - 1] + 1);
            }
        }
        int ret = 0;
        for (int j = 0; j < n; j++)
        {
            vector<int> up(m, 0), down(m, m);
            stack<int> stk;
            for (int i = 0; i < m; i++)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    down[stk.top()] = i;
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            for (int i = 0; i < m; i++)
            {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(area, ret);
            }
        }
        return ret;
    }
};
// @lc code=end
