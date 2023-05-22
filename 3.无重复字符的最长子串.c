/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

//字符的位置都从1开始，但是for循环中下标从零开始
int lengthOfLongestSubstring(char *s)
{
    int i;
    int count = 0, max = 0, start = 1;
    int index[128] = {0}; //记录字符第一次出现的位置
    for (i = 0; s[i] != '\0'; i++)
    {
        /*
        if里面的若成立，说明s[i]在本字串中已经出现过了，否则
        肯定是在start之前更新的，也就是小于start
        这里巧妙地避免了散列
        */
        if (index[s[i]] >= start)
        {
            count = i - start + 1;
            if (count > max)
            {
                max = count;
            }
            start = index[s[i]] + 1;
        }
        index[s[i]] = i + 1;
    }
    count = i - start + 1;
    return max > count ? max : count;
}
// @lc code=end
