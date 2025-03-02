//4 sum by brute force approach
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> Find4Sum(vector<int> arr,int target)
{
    set<vector<int>> ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    if((arr[i]+arr[j]+arr[k]+arr[l])==target)
                    {
                       vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                       sort(temp.begin(),temp.end());
                       ans.insert(temp);
                    }
                }
            }
        }

        
    }
    vector<vector<int>> st(ans.begin(),ans.end());
    return st;
}

int main()
{
    vector<int> arr={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=Find4Sum(arr,target);
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