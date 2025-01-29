#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
   
   int  a[5]={5,4,3,2,1};
    sort(a,a+5);
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    vector<int> v;
    for(i=5;i>=1;i--)
    {
        v.push_back(i);
    }
    sort(v.begin(),v.end());
    for(i=5;i>=1;i--)
    {
       cout<<v[i]<<" ";
    }
    return 0;
}