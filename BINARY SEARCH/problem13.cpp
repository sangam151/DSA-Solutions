//search single element in a sorted array by brute force approach 1
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> & arr)
{
    int n=arr.size();
    if(n==0) return arr[n];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(arr[i]!=arr[i+1]) return arr[i];
            
        }
        else if(i==n-1)
        {
            if(arr[i]!=arr[i-1]) return arr[i];
        }
        else{
            if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]) return arr[i];
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    int ans=singleNonDuplicate(arr);
    cout<<"The single element is: "<<ans<<endl;
    return 0;
}