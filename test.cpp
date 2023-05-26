
int getMinWildcard(vector <string> &strs)
{
    int n = strs.size();
    vector <vector<int>> dp(n, vector<int>(n, INT_MAX));

    // base case
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = count(strs[i].begin(), strs[i].end(), '*');
    }

    // dp transition
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (strs[i].size() > 1 && strs[j].size() > 1)
            {
                string s1 = strs[i].substr(1, strs[i].size() - 2);
                string s2 = strs[j].substr(1, strs[j].size() - 2);
                if (match(s1, s2))
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }

    return dp[0][n - 1];