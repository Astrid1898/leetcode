/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start
inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortColors(int *nums, int numsSize)
{
    int first0 = 0;
    int first2 = numsSize - 1;
    for (int i = 0; i <= first2; i++)
    {
        while (i <= first2 && nums[i] == 2)
        {
            swap(&nums[i], &nums[first2]);
            first2--;
        }
        if (nums[i] == 0)
        {
            swap(&nums[i], &nums[first0]);
            ++first0;
        }
    }
}
// @lc code=end
