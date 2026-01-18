// count Subset with sum k by memoization approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubsets(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums.size() - 1, target, nums, dp);
    }

    int solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        if (index == 0)
            return (nums[0] == target ? 1 : 0);
        if (dp[index][target] != -1)
            return dp[index][target];
        int nonTake = solve(index - 1, target, nums, dp);
        int take = 0;
        if (nums[index] <= target)
        {
            take = solve(index - 1, target - nums[index], nums, dp);
        }
        return dp[index][target] = take + nonTake;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    Solution obj;
    cout << obj.countSubsets(nums, target) << endl;
}