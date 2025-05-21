//by better approach
#include<bits/stdc++.h>
using namespace std;
long double minimizeMaxDistance(vector<int> arr,int k)
{
    int n=arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    //insert the first n-1 element into pq with respecgtive to distance values
    for(int i=0;i<n-1;i++)
    {
        pq.push({arr[i+1]-arr[i],i});
    }
    //pick and place k gas station
    for(int gasstations=1;gasstations<=k;gasstations++)
    {
        //find the maximum section
        //ans insert the gas station
        auto tp=pq.top();
        pq.pop();
        int secInd=tp.second;
        //insert the current gas station
        howMany[secInd]++;
        long double inidiff=arr[secInd+1]-arr[secInd];
        long double newSecLen=inidiff/(long double)(howMany[secInd]+1);
        pq.push({newSecLen,secInd});

    }
    return pq.top().first;

}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int k=4;
    long double ans=minimizeMaxDistance(arr,k);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}