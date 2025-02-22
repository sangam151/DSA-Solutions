//Find the triplets that sum upto zero by brute force approach
#include<bits/stdc++.h>
using namespace std;

set<vector<int>> findTriplets(vector<int> arr)
{
    set<vector<int>> ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);

                }
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr={-1,0,1,2,-1,-4};
    set<vector<int>> ans=findTriplets(arr);
    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}