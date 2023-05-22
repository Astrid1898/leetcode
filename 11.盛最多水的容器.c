/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (a < b ? a : b)
int maxArea(int *height, int heightSize)
{
    int i = 0, j = heightSize - 1;
    int ans = 0;
    while (i < j)
    {
        int area = min(height[i], height[j]) * (j - i);
        ans = max(ans, area);
        if (height[i] <= height[j])
            i++;
        else
        {
            j--;
        }
    }
    return ans;
}
// @lc code=end
