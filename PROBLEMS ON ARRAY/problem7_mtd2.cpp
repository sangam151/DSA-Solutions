//rotate the array left by k places by using reversal algorithm
#include<bits/stdc++.h>
using namespace std;
//Function to reverse the array
void Reverse(int arr[],int start,int end)
{
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
//Function to rotate the element left
void RotateToRight(int arr[],int n,int k)
{
    //reverse first k element
    Reverse(arr,0,k-1);
    //reverse last n-k elements
    Reverse(arr,k,n-1);
    //reverse element of whole array
    Reverse(arr,0,n-1);
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=6;
    int k=3;
    RotateToRight(arr,n,k);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}