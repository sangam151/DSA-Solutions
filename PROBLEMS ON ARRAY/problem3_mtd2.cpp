//Check if the array is sorted or not by optimal approach
#include<bits/stdc++.h>
using namespace std;
bool issorted(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        return false;
        
    }
    return true;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
   bool ans= issorted(arr,n);
   if(ans)cout<<"True";
   else cout<<"False";
    
    
    return 0;
}   