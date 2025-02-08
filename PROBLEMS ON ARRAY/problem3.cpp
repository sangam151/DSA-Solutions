//Check if the array is sorted or not by brute force approach
#include<bits/stdc++.h>
using namespace std;
bool issorted(int arr[],int n)
{
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[i])
        return false;

    }
}
return true;
}
int main(){
    int arr1[]={4,3,2,6,5};
    int arr2[]={1,2,3,4,5};
    int n=5;
    bool ans=issorted(arr2,n);
   
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}