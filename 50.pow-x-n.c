/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
double quickPow(double x, long long n)
{
    if (n == 0)
        return (double)1;
    double y = quickPow(x, n / 2);
    return (n & 1) ? y * y * x : y * y;
}
double myPow(double x, int n)
{
    long long N = n;
    return N > 0 ? quickPow(x, N) : 1.0 / quickPow(x, N);
}
// @lc code=end
