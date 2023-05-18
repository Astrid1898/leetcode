/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

int search(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
        return -1;
    if (numsSize == 1)
        return nums[0] == target ? 0 : -1;
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && nums[right] >= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
// @lc code=end
