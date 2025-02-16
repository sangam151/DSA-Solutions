//Leaders in array by optimal approach
#include<bits/stdc++.h>
using namespace std;
vector<int> arrayLeader(int arr[],int n)
{
    vector<int> ans;
    ans.push_back(arr[n-1]);
    int max=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            ans.push_back(arr[i]);
            max=arr[i];
        }
    }
    return ans;

}
int main(){
    //array initialization
    int arr[]={10, 22, 12, 3, 0, 6};
    int n=6;
    vector<int> ans=arrayLeader(arr,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}