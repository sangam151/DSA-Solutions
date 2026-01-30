// Matrix Chain Multiplication using memoization approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minCost = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int cost1 = solve(arr, i, k, dp);
            int cost2 = solve(arr, k + 1, j, dp);
            int costMultiply = arr[i - 1] * arr[k] * arr[j];
            int total = cost1 + cost2 + costMultiply;
            minCost = min(minCost, total);
        }
        return dp[i][j] = minCost;
    }

    int matrixChainOrder(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 1, n - 1, dp);
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplication is: " << sol.matrixChainOrder(arr) << endl;
}