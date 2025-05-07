//Rearrange Array Elements by Sign by optimal method
#include<bits/stdc++.h>
using namespace std;
vector<int> Rearrangebysign(vector<int> arr,int n)
{
    vector<int> ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
        else
        {
        ans[negIndex]=arr[i];
        negIndex+=2;
        }
    }
    return ans; 
}
int main()
{
    int n=4;
    vector<int> arr={1,2,-4,-5};
    vector<int> ans=Rearrangebysign(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<< ans[i]<<" ";
    }


}