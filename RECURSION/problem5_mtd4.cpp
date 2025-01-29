//Reverse the array using c++ library function
#include<iostream>
#include<algorithm>
using namespace std;
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}
void reversearray(int arr[],int n)
{
    reverse(arr,arr+n);
    printarray(arr,n);
}
int main(){
    int n=5;int arr[]={1,2,3,4,5};
    cout<<"printing the array in reverse order"<<endl;
    reversearray(arr,n);

    return 0;
}