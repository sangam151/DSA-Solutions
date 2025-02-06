#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int i,int n)
{
    if(i==n) return;
    
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
        int temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
    }
    insertionsort(arr,i+1,n);
}
int main(){
    int arr[]={5,7,4,3,1};
    int  n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before using insertion sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionsort(arr,0,n);


    cout<<"After Using insertion sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}