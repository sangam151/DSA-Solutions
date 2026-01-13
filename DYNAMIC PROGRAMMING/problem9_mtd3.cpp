// Grid unique path by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int func(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    temp[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
                        }
            prev = temp;
        }
        return prev[n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m, n, matrix, dp);
    }
};
int main()
{
    vector<vector<int>> maze{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;

    return 0;
}