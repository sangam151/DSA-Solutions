//rotate the array left by k places by using temp array
#include<bits/stdc++.h>
using namespace std;
void RotateToLeft(int arr[],int n,int k)
{
    if(n==0)
    return;
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++)
    {
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++)
    {
        arr[i]=temp[i-n+k];
    }

}
int main(){
    int n=7;
    int k=2;
    int arr[]={1,2,3,4,5,6,7};
    RotateToLeft(arr,n,k);
    cout<<"After rotating the element to left"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}