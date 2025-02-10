//longest subarray of given sum K(positives) by optimal approach
#include<bits/stdc++.h>
using namespace std;
int getLongestArray(vector<int> arr,long long k)
{
    int n=arr.size();
    int left=0,right=0;
    long long sum=arr[0];
    int maxlen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n)sum+=arr[right];
    }
    return maxlen;
}
int main(){
    vector<int> arr={2,3,5,1,9};
    long long k=10;
    int len=getLongestArray(arr,k);
    cout<<"The length of longest subarray is "<<len<<endl;
    return 0;
}