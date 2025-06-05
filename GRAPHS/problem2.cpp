/*Given a grid of size n*m(n is the number of rows and m is the number
 of columns in the grid) consisting of 0's(water) and 1's land)find the
 number of island
 Note(An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically or diagonally in all 8 direction)*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // transverse to the neighbour and mark them if it is the land
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> a = {
        {'0', '1', '1', '0'}, {'0', '1', '1', '0'}, {'0', '0', '1', '0'}, {'0', '0', '0', '0'}, {'1', '1', '0', '1'}};
    Solution s;
    int ans = s.numIslands(a);
    cout << "The number of islands is: " << ans << endl;

    return 0;
}