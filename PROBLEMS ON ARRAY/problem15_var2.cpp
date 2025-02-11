//Check if a pair with given sum exists in Array(2nd variant)
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> arr,int n,int target)
{
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;

            }
        }
    }
}
int main(){
    int n=5;
    vector<int> arr={2,6,5,8,11};
    int target=14;
    vector<int> ans=twoSum(arr,n,target);
    cout<<"this is the answer for varient 2 "<<ans[0]<<"and"<<ans[1]<<endl;

    return 0;
}