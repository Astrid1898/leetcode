/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 */

// @lc code=start
typedef long long ll;

ll divs(ll a, ll b)
{
    if (a < b)
        return 0;
    ll count = 1;
    ll tb = b;
    while ((tb + tb) <= a)
    {
        count += count;
        tb += tb;
    }
    return count + divs(a - tb, b);
}
int divide(int dividend, int divisor)
{
    if (divisor == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
    {
        if (dividend > INT_MIN)
            return -dividend;
        return INT_MAX;
    }
    ll u_divident = labs(dividend);
    ll u_divisor = labs(divisor);
    int sign = dividend ^ divisor;
    ll count = 0;
    count = divs(u_divident, u_divisor);
    return sign < 0 ? (-count) : (count > INT_MAX ? INT_MAX : count);
}
// @lc code=end
