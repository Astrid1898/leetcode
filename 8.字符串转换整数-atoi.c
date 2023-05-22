/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

int myAtoi(char *s)
{
    long long ans = 0;
    _Bool convertible = 0;
    _Bool isPositive = 1;
    int len = strlen(s);
    int index = 0;
    while (s[index] == ' ' && index < len)
    {
        index++;
    }
    if (!(('0' <= s[index] && s[index] <= '9') || (s[index] == '+' || s[index] == '-')))
    {
        return ans;
    }
    else if (s[index] == '+' || s[index] == '-')
    {
        if (s[index] == '-')
            isPositive = 0;
        index++;
    }
    for (; index < len; index++)
    {
        if ('0' <= s[index] && s[index] <= '9')
        {
            int pre = ans;
            ans = ans * 10 + s[index] - '0';
            if (isPositive && ans >= INT_MAX)
            {
                ans = INT_MAX;
                break;
            }
            else if (!isPositive && (-ans) <= INT_MIN)
            {
                ans = INT_MIN;
                break;
            }

            convertible = 1;
        }
        else if (convertible)
        {
            break;
        }
        else
        {
            return 0;
        }
    }
    if (isPositive)
        return ans;
    else
        return -ans;
}
// @lc code=end
