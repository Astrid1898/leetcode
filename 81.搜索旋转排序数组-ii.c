/*
 * @lc app=leetcode.cn id=81 lang=c
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start

bool search(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
        return false;
    if (numsSize == 1)
        return nums[0] == target ? true : false;
    int l = 0, r = numsSize - 1;
    while (l <= r)
    {
        int mid = (r + l) >> 1;
        if (nums[mid] == target)
            return true;
        if (nums[l] == nums[mid])
        {
            l++;
            continue;
        }
        if (nums[l] < nums[mid])
        {
            if (target >= nums[l] && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}
// @lc code=end
