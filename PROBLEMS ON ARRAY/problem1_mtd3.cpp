//Largest Element Of the array by using a max variable
#include<bits/stdc++.h>
using namespace std;
int find_largest(int arr[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }

    }
    return max;
}
int main(){
    int arr1[]={1,2,3,8,6};
    int n=5;
  cout<<"largest element of the array is "<<  find_largest(arr1,n);
    return 0;
}