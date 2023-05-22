/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void generateRight(char **returnArray, int *returnSize, int *left, int *right, int *flag, char *tmp, int n);
void generateLeft(char **returnArray, int *returnSize, int *left, int *right, int *flag, char *tmp, int n);
void generateRight(char **returnArray, int *returnSize, int *left, int *right, int *flag, char *tmp, int n)
{
    (*right)--;
    (*flag)--;
    tmp[n] = ')';
    if ((*left) > 0)
        generateLeft(returnArray, returnSize, left, right, flag, tmp, n + 1);
    if ((*right) > 0 && (*flag) > 0)
        generateRight(returnArray, returnSize, left, right, flag, tmp, n + 1);
    if (*left == 0 && *right == 0)
    {
        returnArray[*returnSize] = malloc(sizeof(int) * (n + 2));
        for (int i = 0; i < n + 1; i++)
        {
            returnArray[*returnSize][i] = tmp[i];
        }
        returnArray[*returnSize][n + 1] = '\0';
        (*returnSize)++;
    }
    (*right)++;
    (*flag)++;
}
void generateLeft(char **returnArray, int *returnSize, int *left, int *right, int *flag, char *tmp, int n)
{
    (*left)--;
    (*flag)++;
    tmp[n] = '(';
    if ((*left) > 0)
        generateLeft(returnArray, returnSize, left, right, flag, tmp, n + 1);
    if ((*right) > 0 && (*flag) > 0)
        generateRight(returnArray, returnSize, left, right, flag, tmp, n + 1);
    (*left)++;
    (*flag)--;
}
char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;
    if (n == 0)
        return NULL;
    char **returnArray = (char **)malloc(sizeof(char *) * 1430);
    int *left = malloc(sizeof(int));
    int *right = malloc(sizeof(int));
    *left = *right = n;
    int flag = 0;
    int *p_flag = &flag;
    char *tmp = malloc(sizeof(char) * (2 * n + 1));
    generateLeft(returnArray, returnSize, left, right, p_flag, tmp, 0);
    free(tmp);
    free(left);
    free(right);
    return returnArray;
}
// @lc code=end
