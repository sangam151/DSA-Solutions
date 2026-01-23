// Target sum by tabulation approach || DP problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;
        int newTarget = (totalSum + target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= newTarget; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][newTarget];
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}