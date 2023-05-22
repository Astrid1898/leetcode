/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    int maxn = len + 2;
    char tmp[maxn << 1]; //转换后的字符串；
    int Len[maxn << 1];  //Len数组，表征回文子串中心到右端点的距离，为了代码简洁，将右端点定义为最右边第一个不是回文子串的字符
    tmp[0] = '@';        //开头增加特殊字符，防止越界；

    //这里对i的取值很关键，2*len是偶数，i最大到2*len-1，也就是tmp[2*len]位置上为s[len-1]
    for (int i = 1; i < 2 * len; i += 2)
    {
        tmp[i] = '#';
        tmp[i + 1] = s[i / 2];
    }
    tmp[2 * len + 1] = '#';
    tmp[2 * len + 2] = '$'; //字符串结尾加一个字符，防止越界
    tmp[2 * len + 3] = '\0';
    len = 2 * len + 1;
    int mx = 0, ans = 0, po = 0, maxPo = 0; //po为取得最大右端点的字符，mx为最大右端点位置,maxPo为臂长最大时的中心位置
    for (int i = 1; i <= len; i++)
    {
        if (mx > i)
            Len[i] = min(mx - i, Len[2 * po - i]);
        else
            Len[i] = 1;
        while (tmp[i + Len[i]] == tmp[i - Len[i]])
        {
            Len[i]++;
        }
        if (Len[i] + i > mx)
        {
            mx = Len[i] + i;
            po = i;
        }
        if (Len[i] > ans)
        {
            maxPo = i;
            ans = Len[i];
        }
    }
    char *ansStr = malloc(sizeof(char) * ans);
    int count = 0;
    for (int i = -ans + 1; i < ans; i++)
    {
        char t = tmp[maxPo + i];
        if (t != '#')
        {
            ansStr[count++] = t;
        }
    }
    ansStr[count] = '\0';
    printf("%s\n", ansStr);
    return ansStr;
}
// @lc code=end
