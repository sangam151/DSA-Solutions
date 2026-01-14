/*DP Ninja and his friend
Problem Statement:  We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j]
gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0)
and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions:
to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙). When Alica and Bob visit a cell,
they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case,
the chocolates need to be considered only once. They cannot go out of the boundary of the given matrix,
we need to return the maximum number of chocolates that Bob and Alice can together collect.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = -1e9;
        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int ans = curr + solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int maximumChocolates(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};
int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int n = grid.size(), m = grid[0].size();
    Solution obj;
    cout << obj.maximumChocolates(n, m, grid) << endl;
    return 0;
}