//Check if a pair with given sum exists in Array by better approach(variant 1) using Hashing
#include<bits/stdc++.h>
using namespace std;
string twoSum(vector<int> arr,int n,int target)
{
   unordered_map<int,int> mpp;
   for(int i=0;i<n;i++)
   {
    int num=arr[i];
    int moreneeded=target-num;
    if(mpp.find(moreneeded)!=mpp.end())
    {
        return "YES";
    }
    mpp[num]=i;

   }
   return "NO";
}
int main(){
    int n=5;
    vector<int> arr={2,6,5,8,11};
    int target=14;
    string ans=twoSum(arr,n,target);
    cout<<"this is the answer for varient 1 "<<ans<<endl;
    return 0;
}