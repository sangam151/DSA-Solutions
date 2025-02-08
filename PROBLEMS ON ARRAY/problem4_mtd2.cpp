//removing duplicate element of the array by using optimal solution
#include<bits/stdc++.h>
using namespace std;
int remove_duplicate(int arr[],int n)
{
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i]=arr[j];
        }

    }
    return i+1;
}
int main(){
        int arr[]={1,1,2,2,3,3,3};
        int n=sizeof(arr)/sizeof(arr[0]);
        int k=remove_duplicate(arr,n);
        cout<<"array after removing duplicate"<<endl;
        for(int i=0;i<k;i++)
        {
            cout<<arr[i]<<" "<<endl;
        }
    return 0;
}