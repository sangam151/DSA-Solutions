//count subarrays sum equals K.
#include<bits/stdc++.h>
using namespace std;
int findAllSubarrays(vector<int> arr,int k)
{
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(sum==k)cnt++;
        }
    }
    return cnt;
}
int main(){
    vector<int> arr={3,1,2,4};
    int k=6;
    int ans=findAllSubarrays(arr,k);
    cout<<"The number of subarray which equals to "<<k<<" is"<<ans<<endl;
    return 0;
}