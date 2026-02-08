// Detect a cycle in directed graph || Topological Sort
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasCycle(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (int neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
            return count != V;
        }
    }
};
int main()
{
    int V = 4;
    vector<vector<int>> adj = {{1}, {2}, {3}, {1}};
    Solution obj;
    if (obj.hasCycle(V, adj))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle\n"
             << endl;
    }
}