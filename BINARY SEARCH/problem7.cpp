//last occurance in a sorted array by native approach
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int key,vector<int> v)
{
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]==key) return i;
    }
    return -1;
}
int main()
{
    int n=7;
    int key=13;
    vector<int> v={3,4,13,13,13,20,40};
    //returning the last occuring index otherwise return -1
    cout<<solve(n,key,v)<<endl;
    return 0;
}