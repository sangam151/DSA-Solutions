// maximum sum of Non Adjacent elements by memotization method
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return arr[0];
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + solve(arr, i - 2, dp);
        int notPick = solve(arr, i - 1, dp);
        return dp[i] = max(pick, notPick);
    }
    int maximumAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n - 1, dp);
    }
};
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;
    cout << obj.maximumAdjacentSum(arr);
    return 0;
}