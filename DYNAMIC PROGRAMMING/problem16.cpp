// Partition set into 2 subset with minimum absolute sum difference by memoization approach
#include <bits/stdc++.h>
using namespace std;
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[ind] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
    {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
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