// Dijkstra algorithm using priority queue
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto it : adj[node])
            {
                int next = it[0];
                int wt = it[1];
                if (dist[node] + wt < dist[next])
                {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist;
    }
};
int main()
{
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}