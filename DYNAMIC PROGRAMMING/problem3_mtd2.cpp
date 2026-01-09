// frog jump problem by tabulation approach || DP problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int frogJump(const vector<int> &height)
    {
        if (height.empty())
            return 0;
        int n = (int)height.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int ind = 1; ind < n; ind++)
        {
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
            int jumpTwo = INT_MAX;
            if (ind > 1)
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 1]);
            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n - 1];
    }
};
int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    Solution sol;
    cout << sol.frogJump(height) << endl;
    return 0;
}