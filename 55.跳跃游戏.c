/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#define Max(a, b) (a) > (b) ? (a) : (b);

bool canJump(int *nums, int numsSize)
{
    int rightMost = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i <= rightMost)
        {
            rightMost = Max(rightMost, i + nums[i]);
            if (rightMost >= numsSize - 1)
                return true;
        }
    }
    return false;
}
// @lc code=end
