//Find out how many times the array has been rotated by brute force approach
#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> & arr)
{
    int n=arr.size();
    int ans=INT_MAX,index=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<ans)
        {
            ans=arr[i];
            index=i;
        }
    }
    return index;
}
int main()
{
    vector<int> arr={4,5,6,7,0,1,2,3};
    int ans=findKRotation(arr);
    cout<<"The array is rotated "<<ans<<" times"<<endl;
    return 0;
}
