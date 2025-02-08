//Largest element of the array
#include<bits/stdc++.h>
using namespace std;
void largest_element(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Largest Element of the array is"<<arr[n-1];
}
int main(){
   int arr[]={1,2,3,4,5};
   int n;
   cin>>n;
   largest_element(arr,n);
    return 0;
}