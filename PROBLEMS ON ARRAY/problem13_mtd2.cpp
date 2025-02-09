//Find the number that appears once, and the other numbers twice by using Better approach 1(hashing)
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
    //declare the hash array of size maxi+1
    //and hash the given array
    vector<int> hash(maxi+1,0);
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    //find the single element and return the value
    for(int i=0;i<n;i++)
    {
        if(hash[arr[i]]==1)
        return arr[i];
    }


}
int main(){
    vector<int> arr={4,1,2,1,2};
    int ans=getSingleElement(arr);
    cout<<"the number that appears once is "<<ans;
    return 0;
}