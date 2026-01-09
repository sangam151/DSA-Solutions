// Frog Jump by memoization approach || DP 3
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int ind, vector<int> &height, vector<int> &dp)
    {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int Jump2 = INT_MAX;

        int Jump1 = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
        if (ind > 1)
            Jump2 = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        return dp[ind] = min(Jump1, Jump2);
    }
    int frogJump(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int n = (int)height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp);
    }
};
int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    Solution sol;
    cout << sol.frogJump(height) << endl;
    return 0;
}