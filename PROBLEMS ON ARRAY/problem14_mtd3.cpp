//longest subarray of given sum K(positives) by brute force approach
#include<bits/stdc++.h>
using namespace std;
int getLongestArray(vector<int> arr,long long k)
{
   int n=arr.size();//size of the array
   map<long long,int> preSumMap;
   long long sum=0;
   int maxlen=0;
   for(int i=0;i<n;i++)
   {
    //calsulate the prefix index till indix i
    sum+=arr[i];
    //if the sum==k update the maxlen
    if(sum==k)
    maxlen=max(maxlen,i+1);
    //calculate the sum of remaining part
    long long rem=sum-k;
    //calculate the length and update the maxlen
    if(preSumMap.find(rem)!=preSumMap.end())
    {
        int len=i-preSumMap[rem];
        maxlen=max(maxlen,len);
    }
    //Finally, update the map checking the conditions:
    if (preSumMap.find(sum) == preSumMap.end()) {
        preSumMap[sum] = i;
    }

   }
   return maxlen;   

}
int main(){
    vector<int> arr={2,0,0,3};
    long long k=3;
    int len=getLongestArray(arr,k);
    cout<<"The length of longest subarray is "<<len<<endl;
    return 0;
}