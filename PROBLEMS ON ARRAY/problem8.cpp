//move zeros to end by brute force approach
#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n,vector<int> arr)
{
    //temporary array
    vector<int> temp;
    //copy non zero element from original->temp array
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            temp.push_back(arr[i]);
        }
    }
    int nz=temp.size();
    //copy element from temp->original array
    for(int i=0;i<nz;i++)
    {
        arr[i]=temp[i];
    }
    //fill rest of the cells with 0
    for(int i=nz;i<n;i++)
    {
        arr[i]=0;
    }
    return arr;

}
int main(){
    vector<int> arr={1,0,2,3,2,0,0,4,5,1};
    int n=10;
    vector<int> ans=moveZeros(n,arr);
    for(auto &it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}