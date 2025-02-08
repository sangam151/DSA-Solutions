//rotate the array by k places by using temp array
#include<bits/stdc++.h>
using namespace std;
void RotateToRight(int arr[],int n,int k)
{
    if(n==0)
    return;
    k=k%n;
    int temp[k];
    for(int i=n-k;i<n;i++)
    {
        temp[i-n+k]=arr[i];
    }
    for(int i=n-k-1;i>=0;i--)
    {
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++)
    {
        arr[i]=temp[i];
    }

}
int main(){
    int n=7;
    int k=2;
    int arr[]={1,2,3,4,5,6,7};
    RotateToRight(arr,n,k);
    cout<<"After rotating the element to right"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}