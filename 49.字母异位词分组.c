/*
 * @lc app=leetcode.cn id=49 lang=c
 *
 * [49] 字母异位词分组
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool *isJudged;
char **sortedStrs;

int cmpfun(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

void sortTheStr(char **strs, int strsSize)
{
    for (int i = 0; i < strsSize; i++)
    {
        unsigned int len = strlen(strs[i]);
        sortedStrs[i] = malloc(sizeof(char) * (len + 1));
        strcpy(sortedStrs[i], strs[i]);
        qsort(sortedStrs[i], len, sizeof(char), cmpfun);
    }
}

bool judge(int i, int j, int aLen, int bLen)
{
    if (aLen != bLen)
        return false;
    if (strcmp(sortedStrs[i], sortedStrs[j]) == 0)
        return true;
    return false;
}
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (strsSize == 0)
        return NULL;
    isJudged = malloc(sizeof(bool) * strsSize);
    memset(isJudged, 0, sizeof(bool) * strsSize);
    char ***ans = malloc(sizeof(char **) * strsSize);
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    sortedStrs = malloc(sizeof(char *) * strsSize);
    sortTheStr(strs, strsSize);

    for (int i = 0; i < strsSize; i++)
    {
        if (isJudged[i])
            continue;
        int cnt = 0;
        for (int j = i + 1; j < strsSize; j++)
        {
            if (judge(i, j, strlen(strs[i]), strlen(strs[j])))
            {
                if (cnt == 0)
                {
                    ans[(*returnSize)++] = malloc(sizeof(char *) * strsSize);
                    ans[(*returnSize) - 1][cnt] = malloc(sizeof(char) * (strlen(strs[i]) + 1));
                    ans[(*returnSize) - 1][cnt + 1] = malloc(sizeof(char) * (strlen(strs[i]) + 1));
                    strcpy(ans[(*returnSize) - 1][cnt++], strs[i]);
                    strcpy(ans[(*returnSize) - 1][cnt++], strs[j]);
                    isJudged[i] = true, isJudged[j] = true;
                }
                else
                {
                    ans[(*returnSize) - 1][cnt] = malloc(sizeof(char) * (strlen(strs[i]) + 1));
                    strcpy(ans[(*returnSize) - 1][cnt++], strs[j]);
                    isJudged[j] = true;
                }
            }
        }
        if (cnt == 0)
        {
            ans[(*returnSize)++] = malloc(sizeof(char *));
            ans[(*returnSize) - 1][cnt] = malloc(sizeof(char) * (strlen(strs[i]) + 1));
            strcpy(ans[(*returnSize) - 1][cnt++], strs[i]);
            isJudged[i] = true;
        }
        (*returnColumnSizes)[(*returnSize) - 1] = cnt;
    }
    free(isJudged);
    return ans;
}
// @lc code=end
