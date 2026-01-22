// count partition with given difference
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPartition(vector<int> &arr, int d)
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;
        int K = (totalSum + d) / 2;
        vector<int> dp(K + 1, 0);
        dp[0] = 1;
        if (arr[0] <= K)
            dp[arr[0]] = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> curr(K + 1, 0);
            curr[0] = 1;
            for (int t = 0; t <= K; t++)
            {
                int notTake = dp[t];
                int take = 0;
                if (arr[i] <= t)
                {
                    take = dp[t - arr[i]];
                }
                curr[t] = take + notTake;
            }
            dp = curr;
        }
        return dp[K];
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 2, 2};
    int d = 1;
    cout << sol.countPartition(arr, d) << endl;
    return 0;
}