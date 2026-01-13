// Minimum falling path sum by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(matrix[n - 1]);
        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> curr(m, 0);
            for (int col = 0; col < m; col++)
            {
                int down = dp[col];
                int downLeft = (col > 0) ? dp[col - 1] : 1e9;
                int downRight = (col < m - 1) ? dp[col + 1] : 1e9;
                curr[col] = matrix[row][col] + min({down, downLeft, downRight});
            }
            dp = curr;
        }
        return *min_element(dp.begin(), dp.end());
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