// Target sum by tabulation space optimized approach || DP problem
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
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int j = newTarget; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[newTarget];
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