//Left rotate the array by using brute force approach
#include<bits/stdc++.h>
using namespace std;
void left_rotate(int arr[],int n)
{
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    cout<<"The array after left rotate"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    left_rotate(arr,n);

    return 0;
}