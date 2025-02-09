//Find the number that appears once, and the other numbers twice by using Better approach 2(map hashing)
#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> arr)
{
    //size of array
    int n=arr.size();
    int maxi=arr[0];
    //find the maximum element
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    //declare the hash map
    //and hash the given array
   map<int,int> mpp;
   for(int i=0;i<n;i++)
   {
    mpp[arr[i]]++;
   }
   for(auto it:mpp)
   {
    if(it.second==1)
    return it.first;
   }
  


}
int main(){
    vector<int> arr={4,1,2,1,2};
    int ans=getSingleElement(arr);
    cout<<"the number that appears once is "<<ans;
    return 0;
}