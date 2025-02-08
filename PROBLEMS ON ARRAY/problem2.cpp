#include<bits/stdc++.h>
using namespace std;
void secondlargest_element(int arr[],int n)
{
sort(arr,arr+n);
int small=arr[1];
int large=arr[n-2];
cout<<"second largest element of the array is"<<large<<endl;
cout<<"second smallest element of the array is"<<small<<endl;

}
int main()
{
    int arr[]={5,9,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    secondlargest_element(arr,n);

    return 0;
}