// Network delay time
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &time : times)
        {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &it : adj[node])
            {
                if (dist[it.first] > time + it.second)
                {
                    dist[it.first] = time + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << sol.networkDelayTime(times, n, k) << endl;
    return 0;
}