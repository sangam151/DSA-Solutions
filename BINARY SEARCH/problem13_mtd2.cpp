//search single element in a sorted array by brute force approach 2(XOR concept)
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> & arr)
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];

    }
    return ans;
}
int main()
{
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    int ans=singleNonDuplicate(arr);
    cout<<"The single element is: "<<ans<<endl;
    return 0;
}