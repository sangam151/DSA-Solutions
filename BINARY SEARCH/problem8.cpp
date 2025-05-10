//count occurance in the array by binary search algorithm
#include<bits/stdc++.h>
using namespace std;
int firstOccurance(vector<int> arr,int n,int x)
{
    int start=0,end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==x)
        {
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>x)
        {
            end=mid-1;

        }
        else{
            start=mid+1;
        }
    }
    return res;
}
int lastOccurance(vector<int> arr,int n,int x)
{
    int start=0,end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==x)
        {
            res=mid;
            start=mid+1;
        }
        else if(arr[mid]>x)
        {
            end=mid-1;

        }
        else{
            start=mid+1;
        }
    }
    return res;
}

pair<int,int> firstAndLastPosition(vector<int> arr,int n,int x)
{
    int first=firstOccurance(arr,n,x);
    if(first==-1) return{-1,-1};
    int last=lastOccurance(arr,n,x);
    return {first,last};    
}
int count(vector<int> arr,int n,int x)
{
    pair<int,int> ans=firstAndLastPosition(arr,n,x);
    if(ans.first==-1) return 0;
    return(ans.second-ans.first+1);
}
int main()
{
    vector<int> arr={2,4,6,8,8,8,11,13};
    int n=8,x=8;
    int ans=count(arr,n,x);
    cout<<"The number of occurance is: "<<ans<<endl;
    return 0;
}