//reverse the array using recursive method
#include<iostream>
using namespace std;
void reversearray(int arr[],int l,int r)
{
    if(l>=r) return;
   
swap(arr[l],arr[r]);
reversearray(arr,l+1,r-1);
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main(){
    int n=5;
    int  arr[]={1,2,3,4,5};
    reversearray(arr,0,n-1);
    printarray(arr,n);
    return 0;
}