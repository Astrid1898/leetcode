/*
 * @Descripttion: 
 * @version: 
 * @Author: Zhao Jiangfeng
 * @Date: 2021-05-18 22:42:09
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2021-05-18 23:34:44
 */
/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution
{
private:
    int memo[30][30][31];
    string s1, s2;

public:
    bool checkIfsimilar(int i1, int i2, int length)
    {
        unordered_map<int, int> freq;
        for (int i = i1; i < i1 + length; i++)
            freq[s1[i]]++;
        for (int i = i2; i < i2 + length; i++)
            freq[s2[i]]--;
        if (any_of(freq.begin(), freq.end(), [](const auto &entry)
                   { return entry.second != 0; }))
            return false;
        return true;
    }
    bool dfs(int i1, int i2, int length)
    {
        if (memo[i1][i2][length])
            return memo[i1][i2][length] == 1;
        if (s1.substr(i1, length) == s2.substr(i2, length))
        {
            memo[i1][i2][length] = 1;
            return true;
        }
        if (!checkIfsimilar(i1, i2, length))
        {
            memo[i1][i2][length] = -1;
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i))
            {
                memo[i1][i2][length] = 1;
                return true;
            }
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i))
            {
                memo[i1][i2][length] = 1;
                return true;
            }
        }
        memo[i1][i2][length] = -1;
        return false;
    }
    bool isScramble(string s1, string s2)
    {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};

Solution s;
s.isScramble("abc", "abc")
    // @lc code=end
