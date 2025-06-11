//number of islands 
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &mat)
    {
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow=row+i;
                int ncol=col+j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&vis[nrow][ncol]==0 && mat[nrow][ncol]==1)
                {
                    dfs(nrow,ncol,vis,mat);
                }
            }
        }

    }
    public:
    int findIsland(int n,int m,vector<vector<int>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && mat[i][j]==1)
                {
                    cnt++;
                    dfs(i,j,vis,mat);
                }

            }
        }
        return cnt;

    }
};
int main()
{
    vector<vector<int>> mat={
        {0,1,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,0,1}
    };
    Solution obj;
    int ans=obj.findIsland(5,4,mat);
    cout<<"the number of island is: "<<ans<<endl;
    return 0;
}