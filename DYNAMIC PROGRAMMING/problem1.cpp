// Fibonacci using Memoization approach || DP problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }
};
int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.fib(n, dp);
    return 0;
}