// count Subset with sum k by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubsets(vector<int> &nums, int K)
    {
        int n = nums.size();
        vector<int> dp(K + 1, 0);
        dp[0] = 1;
        if (nums[0] <= K)
            dp[nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(K + 1, 0);
            curr[0] = 1;
            for (int target = 0; target <= K; target++)
            {
                int nonTake = dp[target];
                int take = 0;
                if (nums[i] <= target)
                    take = dp[target - nums[i]];
                curr[target] = nonTake + take;
            }
            dp = curr;
        }
        return dp[K];
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int k = 6;
    Solution obj;
    cout << obj.countSubsets(nums, k) << endl;
}