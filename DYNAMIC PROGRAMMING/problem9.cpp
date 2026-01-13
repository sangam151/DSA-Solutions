// Grid Unique paths 2 by memoization approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int func(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = func(i - 1, j, matrix, dp);
        int left = func(i, j - 1, matrix, dp);
        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, matrix, dp);
    }
};
int main()
{
    vector<vector<int>> maze{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;

    return 0;
}