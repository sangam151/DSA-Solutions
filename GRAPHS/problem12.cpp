//cycle detection in directed graph
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    bool dfsCheck(int node,vector<int> adj[],int visit[],int pathVisit[])
    {
        visit[node]=1;
        pathVisit[node]=1;
        //traverse adjacent nodes
        for(auto it:adj[node])
        {
            //when the node id not visited
            if(!visit[it])
            {
                if(dfsCheck(it,adj,visit,pathVisit)==true)
                return true;
            }
            //if node has been previously visited
            //but it has to be visited on the same path
            else if(pathVisit[it])
            {
                return true;
            }
        }
        pathVisit[node]=0;
        return false;
    }
    public:
    bool isCyclic(int V,vector<int> adj[])
    {
        int visit[V]={0};
        int pathVisit[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
            {
                if(dfsCheck(i,adj,visit,pathVisit)==true) return true;

            }
        }
        return false;
    }
};
int main()
{
    //V=11,E=11
    vector<int> adj[11]={{},{2},{3},{4,7},{5},{6},{},{5},{9},{10},{8}};
    int V=11;
    Solution obj;
    bool ans=obj.isCyclic(V,adj);
    if(ans)cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}