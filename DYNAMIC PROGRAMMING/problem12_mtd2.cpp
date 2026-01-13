// minimum falling sum path by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int col = 0; col < m; col++)
            dp[n - 1][col] = matrix[n - 1][col];
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col < m; col++)
            {
                int down = dp[row + 1][col];
                int downLeft = (col > 0) ? dp[row + 1][col - 1] : 1e9;
                int downRight = (col < m - 1) ? dp[row + 1][col + 1] : 1e9;
                dp[row][col] = matrix[row][col] + min({down, downLeft, downRight});
            }
        }
        int minSum = *min_element(dp[0].begin(), dp[0].end());
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