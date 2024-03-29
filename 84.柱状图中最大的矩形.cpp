/*
 * @Descripttion: 
 * @version: 
 * @Author: Zhao Jiangfeng
 * @Date: 2021-05-16 17:54:38
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2021-05-16 20:24:44
 */
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        stack<int> monoStack;
        for (int i = 0; i < n; i++)
        {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i])
            {
                right[monoStack.top()] = i;
                monoStack.pop();
            }
            left[i] = (monoStack.empty() ? -1 : monoStack.top());
            monoStack.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
// @lc code=end
