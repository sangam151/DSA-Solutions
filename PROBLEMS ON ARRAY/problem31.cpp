//maximum sum upto zero by brute force approach
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int> arr)
{
    int n=arr.size();
    unordered_map<int,int> mpp;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            maxlen=i+1;
        }
        else if(mpp.find(sum)!=mpp.end())
        {
            maxlen=max(maxlen,i-mpp[sum]);

        }
        else{
            mpp[sum]=i;
        }

    }
    return maxlen;

}

int main(){
    vector<int> arr={9,-3,3,-1,6,-5};
    cout<<maxSum(arr);
    
    return 0;
}