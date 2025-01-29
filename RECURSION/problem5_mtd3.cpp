//Reverse the array using Space-optimized iterative method
#include<iostream>
using namespace std;
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
void reversearray(int arr[],int n)
{
    int p1=0,p2=n-1;
    while(p1<p2)
    {
        swap(arr[p1],arr[p2]);
        p1++; p2--;
    }
    printarray(arr,n);
}

int main(){
    int n=5;
    int arr[]={1,2,3,4,5};
    cout<<"printing the array in reverse order"<<endl;
    reversearray(arr,n);
    return 0;
}