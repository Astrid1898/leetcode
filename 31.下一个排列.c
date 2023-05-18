/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 */

// @lc code=start

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b, *b = t;
}
void reverse(int *nums, int left, int right)
{
    while (left < right)
    {
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}
void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 2;
    for (; i >= 0 && nums[i] >= nums[i + 1]; i--)
        ;
    if (i >= 0)
    {
        int j = numsSize - 1;
        while (j >= 0 && nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums + i, nums + j);
    }
    reverse(nums, i + 1, numsSize - 1);
}
// @lc code=end
