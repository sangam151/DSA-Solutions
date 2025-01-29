//Reverse the array using extra array
#include<iostream>
using namespace std;
void printarray(int ans[],int n);
void reversearray(int arr[],int n)
{
    int ans[n];
    for(int i=n-1;i>=0;i--)
    {
        ans[n-i-1]=arr[i];
    }
    printarray(ans,n);
}
void printarray(int ans[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
}
int main(){
    int n=5;
    int arr[]={1,2,3,4,5};
    cout<<"printing the array in reverse order"<<endl;
    reversearray(arr,n);
    return 0;
}