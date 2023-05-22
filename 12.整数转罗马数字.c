/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start

char *intToRoman(int num)
{
    int characters[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char symbol[13][3] = {"I", "IV", "V", "IX",
                          "X",
                          "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    char *ans = (char *)malloc(sizeof(char) * 20);
    int size = 0;
    int cycle = 12;
    ans[0] = '\0';
    while (num != 0)
    {
        int quotient = num / characters[cycle];
        int reminder = num - quotient * characters[cycle];
        {

            for (int i = 0; i < quotient; i++)
            {
                strcat(ans, symbol[cycle]);
                size += strlen(symbol[cycle]);
                ans[size] = '\0';
            }
        }
        num = reminder;
        cycle--;
    }
    return ans;
}
// @lc code=end
