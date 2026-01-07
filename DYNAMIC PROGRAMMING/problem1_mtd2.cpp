// Fibonacci using Tabulation approach || DP problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int prev2 = 0;
        int prev = 1;
        int curr;
        for (int i = 2; i <= n; i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.fib(n);
    return 0;
}