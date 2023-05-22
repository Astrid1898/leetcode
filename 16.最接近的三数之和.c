/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
int cmpfun(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmpfun);
    int error = __INT_MAX__;
    int pre = error;
    int ans;

    for (int first = 0; first < numsSize - 2; first++)
    {
        int third = numsSize - 1;
        for (int second = first + 1; second < numsSize - 1; second++)
        {
            int goal = target - nums[first] - nums[second];

            while (third > second && nums[third] > goal)
                --third;
            if (third != numsSize - 1)
            {
                if (abs(nums[third] - goal) > abs(nums[third + 1] - goal))
                    third = third + 1;
            }
            if (third == second)
                third = third + 1;
            if (nums[third] == goal)
                return target;
            if (abs(nums[third] - goal) < error)
            {
                error = abs(nums[third] - goal);
                ans = nums[first] + nums[second] + nums[third];
            }
        }
    }
    return ans;
}
// @lc code=end
