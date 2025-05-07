//Check if a pair with given sum exists in Array(1st variant)
#include<bits/stdc++.h>
using namespace std;
string twoSum(vector<int> arr,int n,int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target) return "YES";
        }
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