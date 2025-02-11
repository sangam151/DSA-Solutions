//Check if a pair with given sum exists in Array(2nd variant) using hashing (better approach)
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> arr,int n,int target)
{
   unordered_map<int,int> mpp;
   for(int i=0;i<n;i++)
   {
    int num=arr[i];
    int moreneeded=target-num;
    if(mpp.find(moreneeded)!=mpp.end())
    {
        return{mpp[moreneeded],i};
    }
    mpp[num]=i;

   }
   return {-1,1};
}
int main(){
    int n=5;
    vector<int> arr={2,6,5,8,11};
    int target=14;
   vector<int> ans=twoSum(arr,n,target);
    cout<<"this is the answer for varient 1 "<<ans[0]<<"and"<<ans[1]<<endl;
    return 0;
}