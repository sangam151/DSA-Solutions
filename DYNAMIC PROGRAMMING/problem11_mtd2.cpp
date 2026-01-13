// Minimum path sum in traingular grid by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int minimumPathSum(vector<vector<int>> &traingle, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = traingle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = traingle[i][j] + dp[i + 1][j];
                int diag = traingle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> traingle{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    int n = traingle.size();
    cout << obj.minimumPathSum(traingle, n);
    return 0;
}