// Minimum path sum by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = matrix[i][j];
                }
                else
                {
                    int up = matrix[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    int left = matrix[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;

                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
        return prev[m - 1];
    }
};
int main()
{
    vector<vector<int>> matrix = {{5, 9, 6}, {11, 5, 2}};
    Solution sol;
    cout << "Minimum path sum in Grid is: " << sol.minPathSum(matrix) << endl;
    return 0;
}