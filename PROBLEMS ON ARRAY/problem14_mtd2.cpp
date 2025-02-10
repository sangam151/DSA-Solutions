//longest subarray of given sum K(positives) by optimizing the brute force approach
#include<bits/stdc++.h>
using namespace std;
int getLongestArray(vector<int> arr,long long k)
{
    int n=arr.size();//size of array
    int len=0;
    for(int i=0;i<n;i++)//staring index
    {
        long long s=0;
        for(int j=i;j<n;j++)//ending index
        {
          s+=arr[j];
            
            if(s==k) 
            len=max(len,j-i+1);
        }
    }
    return len;
}
int main(){
    vector<int> arr={2,3,5,1,9};
    long long k=10;
    int len=getLongestArray(arr,k);
    cout<<"The length of longest subarray is "<<len<<endl;
    return 0;
}