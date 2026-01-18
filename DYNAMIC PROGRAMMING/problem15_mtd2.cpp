// partition equal subset sum by tabulation approach
#include <bits/stdc++.h>
using namespace std;

bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    if (totSum % 2 == 1)
        return false;
    int k = totSum / 2;
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
    return dp[n - 1][k];
}
int main()
{
    vector<int> arr = {2, 2, 2, 2, 4, 4};
    int n = arr.size();
    if (canPartition(n, arr))
    {
        cout << "The Array can be partitioned into two equal parts" << endl;
    }
    else
        cout << "The Array cannot be partitioned into two equal parts" << endl;
    return 0;
}
