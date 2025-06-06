// Flood Fill algorithm
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &arr, int sr, int sc, int newColor)
{
    int m = arr.size(), n = arr[0].size();
    queue<pair<int, int>> q;
    
    q.push({sr, sc});
    int originalColor = arr[sr][sc];
    arr[sr][sc] = newColor;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n)
            {
                if (arr[nrow][ncol] == originalColor)
                {
                    arr[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    return arr;
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1;

    vector<vector<int>> ans = floodFill(arr, sr, sc, 2);
    int m = ans.size(), n = ans[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}