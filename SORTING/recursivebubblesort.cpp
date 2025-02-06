//Recursive Bubble Sort Algorithm
#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[],int n)
{
    if(n==1) return;
    for(int i=0;i<=n-2;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    bubblesort(arr,n-1);
}
int main(){
    int arr[]={5,7,4,3,1};
    int  n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before using Bubble sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort(arr,n);
    cout<<"After Using Bubble Sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}