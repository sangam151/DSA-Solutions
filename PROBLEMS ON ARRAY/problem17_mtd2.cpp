//Find the Majority Element that occurs more than N/2 times by better approach(using hashing)
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> arr)
{
    int n=arr.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it:mpp)
    {
        if(it.second>(n/2))
        return it.first;
    }
}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int ans=majorityElement(arr);
    cout<<"the majority element occurs more than N/2 is "<<ans<<endl;

    return 0;
}