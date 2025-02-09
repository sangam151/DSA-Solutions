//Find the missing number in the array by optimal approach 2(XOR approach)
//XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
//XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.
 
#include<bits/stdc++.h>
using namespace std;
int MissingNumber(vector<int> arr,int N)
{
    int xor1=0,xor2=0;
    for(int i=0;i<N-1;i++)
    {
        xor1=xor1^arr[i];//xor of array element 
        xor2=xor2^(i+1);//xor up to N-1
    }
    xor2=xor2^N;//Xor Upto N
    return (xor1^xor2);

}
int main(){
    int N=5;
    vector<int> arr={1,2,4,5};
    int ans=MissingNumber(arr,N);
    cout<<"the missing number is"<<ans<<endl;  
   
    return 0;
}