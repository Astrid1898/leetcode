/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 */

// @lc code=start
void swapPointer(char *a, char *b)
{
    char *tmp = a;
    a = b;
    b = tmp;
}
void swapInter(int *a, int *b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}
void subAdd(char *ans, char *multiplicand, int carry, int *ansCount, int multiplicandLen)
{
    int ans_i = 0, carry_i = 0, multiplicand_i = 0;
    int sign = 0;
    while (ans_i < (*ansCount) && carry_i < carry)
    {
        ans_i++;
        carry_i++;
    }
    while (carry_i < carry)
    {
        ans[ans_i++] = '0';
        carry_i++;
    }
    while (ans_i < (*ansCount) && multiplicand_i < multiplicandLen)
    {
        int a = ans[ans_i] - '0';
        int b = multiplicand[multiplicand_i++] - '0';
        int sum = a + b + sign;
        if (sum > 9)
        {
            sign = 1;
            sum -= 10;
        }
        else
        {
            sign = 0;
        }
        ans[ans_i++] = (char)('0' + sum);
    }
    while (multiplicand_i < multiplicandLen)
    {
        if (sign)
        {
            int a = multiplicand[multiplicand_i++];
            a = a + sign;
            if (a > 9)
            {
                sign = 1;
                a -= 10;
            }
            else
            {
                sign = 0;
            }
            ans[ans_i++] = (char)('0' + a);
        }
        else
        {
            ans[ans_i++] = multiplicand[multiplicand_i++];
        }
    }
    while (sign)
    {
        if (ans_i < *ansCount)
        {
            int a = ans[ans_i] - '0';
            a = a + sign;
            if (a > 9)
            {
                sign = 1;
                a -= 10;
            }
            else
            {
                sign = 0;
            }
            ans[ans_i++] = (char)('0' + a);
        }
        else
        {
            ans[ans_i++] = '1';
            sign = 0;
        }
    }
    if (ans_i > (*ansCount))
        *ansCount = ans_i;
}
char *multiply(char *num1, char *num2)
{
    if (num1[0] == '0' || num2[0] == '0')
    {
        char *ans = malloc(sizeof(char) * 2);
        ans[0] = '0', ans[1] = '\0';
        return ans;
    }
    char *ans = malloc(sizeof(char) * 230);
    char *multiplicand = num1;
    char *multiplier = num2;
    int multiplicandLen = strlen(num1);
    int multiplierLen = strlen(num2);
    if (multiplicandLen < multiplierLen)
    {
        swapPointer(multiplicand, multiplier);
        swapInter(&multiplicandLen, &multiplierLen);
    }
    int ansCount = 0;
    for (int i = 0; i < multiplicandLen / 2; i++)
    {
        char tmp = multiplicand[i];
        multiplicand[i] = multiplicand[multiplicandLen - 1 - i];
        multiplicand[multiplicandLen - 1 - i] = tmp;
    }
    for (int i = 0; i < multiplierLen; i++)
    {
        int times = multiplier[i] - '0';
        while (times--)
            subAdd(ans, multiplicand, multiplierLen - i - 1, &ansCount, multiplicandLen);
    }
    ans[ansCount] = '\0';
    for (int i = 0; i < ansCount / 2; i++)
    {
        char tmp = ans[i];
        ans[i] = ans[ansCount - 1 - i];
        ans[ansCount - 1 - i] = tmp;
    }
    return ans;
}
// @lc code=end
