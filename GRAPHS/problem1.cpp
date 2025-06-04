/*problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single 
province if there is a path from u to v or v to u. Your task is to find the number of provinces.*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    //dfs transversal function
    void dfs(int node,vector<int> adjLs[],int vis[])
    {
        //mark the node as visited
        vis[node]=1;
        for(auto it:adjLs[node])
        {
            if(!vis[it])
            {
                dfs(it,adjLs,vis);
            }
        }
    }
    public:
    int numProvinces(vector<vector<int>> adj,int V)
    {
        vector<int> adjLs[V];
        //to change adjancency matrix to list 
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                //self node are not considered
                if(adj[i][j]==1 && i!=j)
                {
                    adjLs[i].push_back(j);
                    //adjLs[j].push_back(i);
                }

            }
        }
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            //if node is not visited
            if(!vis[i])
            {
                //counter to count the number of matrix
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;

    }
};
int main()
{
    vector<vector<int>> adj
    {
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };
    Solution ob;
    cout<<ob.numProvinces(adj,3)<<endl;
    return 0;
}