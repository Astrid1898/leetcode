/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static char alpha[8][4] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
static int limit[8] = {3, 3, 3, 3, 3, 4, 3, 4};

void recursive(char *number, int *answer, int index, int depth, char **ans, int *pathId)
{
    if (index == depth)
    {
        ans[*pathId] = malloc(sizeof(char) * (depth + 1));
        for (int i = 0; i < depth; i++)
        {
            ans[*pathId][i] = alpha[number[i] - '2'][answer[i]];
        }
        ans[*pathId][depth] = '\0';
        (*pathId)++;
        return;
    }
    for (answer[index] = 0; answer[index] < limit[number[index] - '2']; answer[index]++)
    {
        recursive(number, answer, index + 1, depth, ans, pathId);
    }
}
char **letterCombinations(char *digits, int *returnSize)
{
    int len = strlen(digits);
    *returnSize = 0;
    int a[100] = {0};
    int num = pow(4, len);

    if (len == 0)
        return NULL;
    char **ans = malloc(sizeof(char *) * num);
    recursive(digits, a, 0, len, ans, returnSize);
    return ans;
}
// @lc code=end
