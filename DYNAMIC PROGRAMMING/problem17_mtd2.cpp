// count Subset with sum k by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubsets(vector<int> &nums, int K)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));
        dp[0][0] = 1;
        if (nums[0] <= K)
            dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= K; target++)
            {
                int nonTake = dp[i - 1][target];
                int take = 0;
                if (nums[i] <= target)
                    take = dp[i - 1][target - nums[i]];
                dp[i][target] = nonTake + take;
            }
        }
        return dp[n - 1][K];
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int k = 6;
    Solution obj;
    cout << obj.countSubsets(nums, k) << endl;
}