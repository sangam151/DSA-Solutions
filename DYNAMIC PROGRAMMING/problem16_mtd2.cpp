// Partition set into 2 subset with minimum absolute sum difference by tabulation approach
#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        k += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = notTaken || taken;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= k; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (k - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << "The minimum absolute difference is" << minSubsetSumDifference(arr, n);
    return 0;
}