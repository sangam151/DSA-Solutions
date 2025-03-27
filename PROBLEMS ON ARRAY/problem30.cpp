//Element that appears more than N/3 times in the array by brute force approach
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> arr)
{
    int n=arr.size();
    vector<int> ls;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        if(ls.size()==0 || ls[0]!=arr[i])
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j]==arr[i])cnt++;

            }
            if(cnt>(n/3)) ls.push_back(arr[i]);
            
        }
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