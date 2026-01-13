// Minimum path sum in traingular grid
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int solve(int i, int j, vector<vector<int>> &traingle, int n, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1)
            return traingle[i][j];
        int down = traingle[i][j] + solve(i + 1, j, traingle, n, dp);
        int diag = traingle[i][j] + solve(i + 1, j + 1, traingle, n, dp);
        return dp[i][j] = min(down, diag);
    }
    int minimumPathSum(vector<vector<int>> &traingle)
    {
        int n = traingle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, traingle, n, dp);
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> traingle{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    cout << obj.minimumPathSum(traingle);
    return 0;
}