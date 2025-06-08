// detect graph in undirected graph using dfs transval technique
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
bool dfs(int node,int parent,int vis[],vector<int> adj[])
{
    vis[node]=1;
    //visit adjacent node
    for(auto adjacentNode: adj[node])
    {
        //unvisited adjacent node
        if(!vis[adjacentNode])
        {
            if(dfs(adjacentNode,node,vis,adj)==true)
            return true;
        }
        else if(adjacentNode!=parent) return true;

    }
    return false;
}
public:
    // function to detect cycle in undirected graph
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        // for graph with connected component
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    // V=4,E=2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    return 0;
}
