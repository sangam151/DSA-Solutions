// Subset sum equal to target || Memoization approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
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
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "subset with the given target found";
    else
        cout << "subset with the given target not found";
    return 0;
}