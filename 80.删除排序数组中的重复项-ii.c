/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start

int removeDuplicates(int *nums, int numsSize)
{
    int i = 1, j = 1;
    int cnt = 1;
    while (i < numsSize)
    {
        if (nums[i] == nums[i - 1])
        {
            cnt++;
            if (cnt > 2)
                i++;
            else
                nums[j++] = nums[i++];
        }
        else
        {
            cnt = 1;
            nums[j++] = nums[i++];
        }
    }
    return j;
}
// @lc code=end
