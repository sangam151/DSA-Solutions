// distance of nearest cell having 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // function to find the distance of nearest 1 in the grid for each cell
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // visited and distance matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        //<coordinate,step>
        queue<pair<pair<int, int>, int>> q;
        // transverse the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // start bfs if cell is 1
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        //transverse till the queue is empty
        while(!q.empty())
        {
            int row=q.front().first.first;
             int col=q.front().first.second;
             int steps=q.front().second;
             q.pop();
             dist[row][col]=steps;
             //for all 4 neighbour
             for(int i=0;i<4;i++)
             {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                //check for unvisited cell
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
             }
        }
        return dist;
    }
};
int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}