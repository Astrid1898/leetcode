/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binSearch(int *nums, int numSize, int target, bool low)
{
    int ans = numSize;
    int left = 0;
    int right = numSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (low && nums[mid] >= target))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;
    ans[0] = -1, ans[1] = -1;
    int left = binSearch(nums, numsSize, target, true);
    int right = binSearch(nums, numsSize, target, false) - 1;
    if (left <= right && right < numsSize && nums[left] == target && nums[right] == target)
    {
        ans[0] = left;
        ans[1] = right;
    }
    return ans;
}
// @lc code=end
