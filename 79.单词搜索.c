/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 */

// @lc code=start

int len;
int m;
int n;
bool **flag;

bool verify(char **board, int i, int j, char *word, int idx)
{
    if (idx == len)
        return true;
    if (j + 1 < n && flag[i][j + 1] == false && board[i][j + 1] == word[idx])
    {
        flag[i][j + 1] = true;
        if (verify(board, i, j + 1, word, idx + 1))
        {
            flag[i][j + 1] = false;
            return true;
        }
        flag[i][j + 1] = false;
    }
    if (j - 1 >= 0 && flag[i][j - 1] == false && board[i][j - 1] == word[idx])
    {
        flag[i][j - 1] = true;
        if (verify(board, i, j - 1, word, idx + 1))
        {
            flag[i][j - 1] = false;
            return true;
        }
        flag[i][j - 1] = false;
    }
    if (i + 1 < m && flag[i + 1][j] == false && board[i + 1][j] == word[idx])
    {
        flag[i + 1][j] = true;
        if (verify(board, i + 1, j, word, idx + 1))
        {
            flag[i + 1][j] = false;
            return true;
        }
        flag[i + 1][j] = false;
    }
    if (i - 1 >= 0 && flag[i - 1][j] == false && board[i - 1][j] == word[idx])
    {
        flag[i - 1][j] = true;
        if (verify(board, i - 1, j, word, idx + 1))
        {
            flag[i - 1][j] = false;
            return true;
        }
        flag[i - 1][j] = false;
    }
    return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    len = strlen(word);
    m = boardSize;
    n = boardColSize[0];
    flag = (bool **)malloc(sizeof(bool *) * m);
    for (int i = 0; i < m; i++)
    {
        flag[i] = calloc(n, sizeof(bool));
    }
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[0]; j++)
        {
            if (board[i][j] == word[0])
            {
                flag[i][j] = true;
                if (verify(board, i, j, word, 1))
                    return true;
                flag[i][j] = false;
            }
            else
                continue;
        }
    }
    return false;
}
// @lc code=end
