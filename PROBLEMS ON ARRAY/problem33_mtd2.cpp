//merge two sorted array without using extra space by optimal approach 1
#include<bits/stdc++.h>
using namespace std;
void merge(long long arr1[],long long arr2[],int n,int m)
{
    int left=n-1,right=0;
    while(left>=0 &&right<m)
    {
        if(arr1[left]>arr2[right])
        swap(arr1[left],arr2[right]);
        else
        break;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

}
int main()
{
    long long arr1[]={1,4,8,10},arr2[]={2,3,9};
    int n=4,m=3;
    merge(arr1,arr2,n,m);
    cout<<"The merged array are"<<"\n";
    cout<<"arr1[]= ";
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"\narr2[]= ";
    for(int i=0;i<m;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;


}