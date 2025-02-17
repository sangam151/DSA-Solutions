//longest consecutive sequence in the array by better approach
#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveSequence(vector<int> arr)
{
    int n=arr.size();
    if(n==0)
    {
        return 0;
    }
    sort(arr.begin(),arr.end());
    int lastsmaller=INT_MIN;
    int cnt=0;
    int longest=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-1==lastsmaller)
        {
            cnt+=1;
            lastsmaller=arr[i];
        }
        else 
        {
            cnt=1;
            lastsmaller=arr[i];
        }
        longest=max(longest,cnt);
    }
    return longest;

}
int main(){
    vector<int> arr={100,200,1,2,3,4};
    int ans=longestConsecutiveSequence(arr);
    cout<<"The length of longest consecutive sequence is"<<ans<<endl;

    return 0;
}
