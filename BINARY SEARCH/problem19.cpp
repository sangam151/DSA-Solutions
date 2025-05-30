/*Problem Statement:You are given an array 'arr' of size 'n' which denotes the 
position of stalls.You are also given an integer 'k' which denotes the number 
of aggressive cows.You are given the task of assigning stalls to 'k' cows such 
that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.*/
#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int> arr,int mDist,int k)
{
    int n=arr.size();
    int last=arr[0];
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if((arr[i]-last)>=mDist)
        {
            cnt++;
            last=arr[i];
        }
    }
    if(cnt>=k) return true;
   
    return false;
}
int maximum_possible_minimum(vector<int> arr,int k)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
  
    int maxi=arr[n-1]-arr[0];
    for(int i=1;i<=maxi;i++)
    {
        if(possible(arr,i,k)==false) return i-1;
    }
    return maxi;
}
int main()
{
    vector<int> arr={4,2,1,3,6};
    int k=2;
    int ans=maximum_possible_minimum(arr,k);
    cout<<"The maximum possible minimum distance is "<<ans<<endl;
    return 0;
}
