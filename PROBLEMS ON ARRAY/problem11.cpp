//Find the missing number in the array by brute force approach
#include<bits/stdc++.h>
using namespace std;
int MissingNumber(vector<int> arr,int N)
{

    for(int i=1;i<=N;i++)
    {
        int flag=0;
        for(int j=0;j<N-1;j++)
        {
            if(arr[j]==i) flag=1;

        }
        if(flag==0) return i;
    }

}
int main(){
    int N=5;
    vector<int> arr={1,2,4,5};
    int ans=MissingNumber(arr,N);
    cout<<"the missing number is"<<ans<<endl;  
    return 0;
}