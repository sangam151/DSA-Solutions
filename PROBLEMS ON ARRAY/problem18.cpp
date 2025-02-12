//maximum subarray sum in the array by using kadane's algorithm
#include<bits/stdc++.h>
using namespace std;
int maximumSubarray(vector<int> arr)
{
    int n=arr.size();
    long long sum=0;
    long long maxi=LONG_MIN;
    int start=0;
    int ansStart=-1,ansEnd=-1;
    for(int i=0;i<n;i++)
    {
        if(sum==0)start=i;
        sum+=arr[i];
        if(sum>maxi)
        {
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0)
        sum=0;

    }
    //printing the subarray
    cout<<"The subarray is : [";
    for(int i=ansStart;i<=ansEnd;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]\n";
    return maxi;
}
int main()
{
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans=maximumSubarray(arr);
    cout<<"The maximum subarray sum in the array is : "<<ans<<endl;
    return 0;
}