#include<bits/stdc++.h>
using namespace std;
void getelement(int arr[],int n)
{
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    for(int i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);

    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
        {
            second_small=arr[i];
        }
        if(arr[i]>second_large && arr[i]!=large)
        {
            second_large=arr[i];
        }
    }
    cout<<"second largest element and second smallest element are"<<second_large<<"and"<<second_small<<endl;
}
int main()
{
    int arr[]={1,22,5,6,78,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    getelement(arr,n);
    return 0;
}
