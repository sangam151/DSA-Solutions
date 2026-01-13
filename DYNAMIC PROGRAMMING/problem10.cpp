// Miniumum path sum in a Grid
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int func(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return matrix[m][n];
        if (m < 0 || n < 0)
            return 1e9;
        if (dp[m][n] != -1)
            return dp[m][n];
        int up = matrix[m][n] + func(m - 1, n, matrix, dp);
        int left = matrix[m][n] + func(m, n - 1, matrix, dp);
        return dp[m][n] = min(up, left);
    }

public:
    int minimumPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, matrix, dp);
    }
};
int main()
{
    vector<vector<int>> matrix = {{5, 9, 6}, {11, 5, 2}};
    Solution sol;
    cout << "Minimum path sum in Grid is: " << sol.minimumPathSum(matrix) << endl;
    return 0;
}
