/*
 * @lc app=leetcode.cn id=71 lang=c
 *
 * [71] 简化路径
 */

// @lc code=start

char *simplifyPath(char *path)
{
    char *stack[100];
    int depth = 0;
    for (char *s = strtok(path, "/"); s; s = strtok(NULL, "/"))
    {
        if (strcmp(s, ".") == 0)
            ;
        else if (strcmp(s, "..") == 0)
            depth = fmax(0, depth - 1);
        else
        {
            stack[depth++] = s;
        }
    }
    if (depth == 0)
        return "/";
    char *ans = calloc(1000, sizeof(char));
    for (int i = 0; i < depth; i++)
    {
        strcat(ans, "/");
        strcat(ans, stack[i]);
    }
    return ans;
}
// @lc code=end
