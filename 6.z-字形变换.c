/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start

char *convert(char *s, int numRows)
{
    int len = strlen(s);
    int gap = (numRows - 1) << 1;
    if (gap == 0)
        gap = 1;
    char *ans = malloc(sizeof(char) * (len + 1));
    int count = 0;
    for (int i = 0; i < numRows; i++)
    {
        int index = i;
        if (i == 0 || i == (numRows - 1))
        {
            while (index < len)
            {
                ans[count++] = s[index];
                index += gap;
            }
        }
        else
        {
            int smallGap = gap - (i << 1);
            int relativeGap = i << 1;
            int sign = 0;
            while (index < len)
            {
                if (sign)
                {
                    ans[count++] = s[index];
                    index += relativeGap;
                    sign = 0;
                }
                else
                {
                    ans[count++] = s[index];
                    index += smallGap;
                    sign = 1;
                }
            }
        }
    }
    ans[count] = '\0';
    return ans;
}
// @lc code=end
