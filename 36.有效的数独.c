/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int nums[10] = {0};
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            if (board[i][j] == '.')
                continue;
            int n = (int)(board[i][j] - '0');
            nums[n]++;
            if (nums[n] > 1)
                return false;
        }
        for (int index = 1; index < 10; index++)
            nums[index] = 0;
    }
    for (int i = 0; i < *boardColSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[j][i] == '.')
                continue;
            int n = (int)(board[j][i] - '0');
            nums[n]++;
            if (nums[n] > 1)
                return false;
        }
        for (int index = 1; index < 10; index++)
            nums[index] = 0;
    }
    for (int iCount = 0; iCount < *boardColSize; iCount += 3)
    {
        for (int jCount = 0; jCount < boardSize; jCount += 3)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[iCount + i][jCount + j] == '.')
                        continue;
                    int n = (int)(board[iCount + i][jCount + j] - '0');
                    nums[n]++;
                    if (nums[n] > 1)
                        return false;
                }
            }
            for (int index = 1; index < 10; index++)
                nums[index] = 0;
        }
    }
    return true;
}
// @lc code=end
