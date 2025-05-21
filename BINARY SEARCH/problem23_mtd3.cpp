//by optimal approach
#include<bits/stdc++.h>
using namespace std;
int numberOfGasStationsRequired(long double dist,vector<int> arr)
{
    int n=arr.size();
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        int numberbetween=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])==(dist*numberbetween))
        {
            numberbetween--;
        }
        cnt+=numberbetween;
    }
    return cnt;

}
long double minimizeMaxDistance(vector<int> arr, int k)
{
    int n=arr.size();
    long double high=0,low=0;
    //find maximum distance
    for(int i=0;i<n-1;i++)
    {
        high=max(high,(long double)arr[i+1]-arr[i]);
    }
    //Apply binary search
    long double diff=1e-6;
    while(high-low>diff)
    {
        long double mid=(low+high)/2.0;
        int cnt=numberOfGasStationsRequired(mid,arr);
        if(cnt>k)
        {
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;  
}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int k=4;
    long double ans=minimizeMaxDistance(arr,k);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}