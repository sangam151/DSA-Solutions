//Find the missing number in the array by better approach
#include<bits/stdc++.h>
using namespace std;
int MissingNumber(vector<int> arr,int N)
{
    int hash[N+1]={0};
    //sorting the frequencies
    for(int i=0;i<N-1;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(hash[i]==0)
        return i;
    }
    return -1;
}
int main(){
    int N=5;
    vector<int> arr={1,2,4,5};
    int ans=MissingNumber(arr,N);
    cout<<"the missing number is"<<ans<<endl;  
   
    return 0;
}