//union of two array by using set
#include<bits/stdc++.h>
using namespace std;
vector<int> FindUnion(int arr1[],int arr2[],int n,int m)
{
    vector<int> Union;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        s.insert(arr2[i]);
    }
    for(auto &it:s)
    {
        Union.push_back(it);

    }
    return Union;
}
int main(){
        int arr1[]={1,2,3,4,5,6,7,8,9,10};
        int arr2[]={2,3,4,4,5,11,12};
        int n=10;
        int m=7;
        vector<int> Union= FindUnion(arr1,arr2,n,m);
        cout<<"union of arr1 and arr2 is"<<endl;
        for(auto &it:Union)
        {
            cout<<it<<" ";
        }
    return 0;
}