// Number of Enclaves
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        // check for top right left and buttom
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinate and unvisited 0's
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    int fill(int n, int m, vector<vector<int>> mat)
    {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // transverse first and last row
        for (int j = 0; j < m; j++)
        {
            // check for unvisited 0's and 1's in boundary rows(first row)
            if (!vis[0][j] && mat[0][j] == 1)

                dfs(0, j, vis, mat, delrow, delcol);

            //(last row)
            if (!vis[n - 1][j] && mat[n - 1][j] == 1)

                dfs(n - 1, j, vis, mat, delrow, delcol);
        }
        for (int i = 0; i < n; i++)
        {
            // check for unvisited 0's and 1's in boundary rows(first column)
            if (!vis[i][0] && mat[i][0] == 1)

                dfs(i, 0, vis, mat, delrow, delcol);

            //(last column)
            if (!vis[i][m - 1] && mat[i][m - 1] == 1)

                dfs(i, m - 1, vis, mat, delrow, delcol);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && mat[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    Solution obj;
    int ans = obj.fill(4, 4, mat);
    cout << "number of encalves is: " << ans << endl;

    return 0;
}