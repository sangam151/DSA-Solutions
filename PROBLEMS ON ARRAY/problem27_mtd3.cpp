//count subarrays sum equals K by optimal approach
#include<bits/stdc++.h>
using namespace std;
int findAllsubArraysWithGivenSum(vector<int> arr,int k)
{
    int n=arr.size();
    int presum=0;
    int cnt=0;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;

    }
    return cnt;
}
int main(){
    vector<int> arr={3,1,2,4};
    int k=6;
    int cnt=findAllsubArraysWithGivenSum(arr,k);
    cout<<"The number of subarrays sum equals to k is "<<cnt<<endl;
    return 0;
}