// minimum falling path sum by memoization approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (col < 0 || col >= matrix[0].size())
            return 1e9;
        if (row == matrix.size() - 1)
            return matrix[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = dfs(row + 1, col, matrix, dp);
        int downLeft = dfs(row + 1, col - 1, matrix, dp);
        int downRight = dfs(row + 1, col + 1, matrix, dp);
        int ans = matrix[row][col] + min({down, downLeft, downRight});
        return dp[row][col] = ans;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int minSum = 1e9;
        for (int col = 0; col < m; col++)
        {
            minSum = min(minSum, dfs(0, col, matrix, dp));
        }
        return minSum;
    }
};
int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 3, 1},
        {2, 3, -1, -1},
        {1, 1, -1, 8}};

    Solution sol;
    cout << "Minimum Falling Path Sum: " << sol.minFallingPathSum(matrix) << endl;

    return 0;
}