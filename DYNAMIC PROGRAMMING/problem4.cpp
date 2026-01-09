// Frog Jump with K Distance by memoization approach || DP 3
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int ind, vector<int> &height, vector<int> &dp, int k)
    {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int mmSteps = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (ind - i >= 0)
            {
                int Jump = solve(ind - i, height, dp, k) + abs(height[ind] - height[ind - i]);
                mmSteps = min(mmSteps, Jump);
            }
        }

        return dp[ind] = mmSteps;
    }
    int frogJump(vector<int> &height, int k)
    {
        if (height.empty())
            return 0;
        int n = (int)height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp, k);
    }
};
int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    Solution sol;
    cout << sol.frogJump(height, 2) << endl;
    return 0;
}