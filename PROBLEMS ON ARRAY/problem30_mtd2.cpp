//Element that appears more than N/3 times in the array by better approach
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> arr)
{
    int n=arr.size();
    vector<int> ls;
    map<int,int> mpp;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){ls.push_back(arr[i]);}
        if(ls.size()==2)break;
    }
    return ls;
    
    
}
int main(){
    vector<int> arr={11,33,33,11,33,11};
    vector<int> ans=majorityElement(arr);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
   
    return 0;
}