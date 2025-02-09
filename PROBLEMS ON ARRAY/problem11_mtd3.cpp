//Find the missing number in the array by optimal approach 1 (summation approach)
#include<bits/stdc++.h>
using namespace std;
int MissingNumber(vector<int> arr,int N)
{
    int s1=(N*(N+1))/2;
    int s2=0;
    for(int i=0;i<N-1;i++)
    {
        s2=s2+arr[i];
    }
    return (s1-s2);

}
int main(){
    int N=5;
    vector<int> arr={1,2,4,5};
    int ans=MissingNumber(arr,N);
    cout<<"the missing number is"<<ans<<endl;  
   
    return 0;
    
}