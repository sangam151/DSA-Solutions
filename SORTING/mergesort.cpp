#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }
    while(left<=mid)
    {
         temp.push_back(arr[left]);
            left++;
    }
    while(right<=high)
    {
         temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int> &arr,int low,int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
        vector<int> arr={5,4,3,2,1};
        int n;
        cout<<"enter the value of number of vector"<<endl;
        cin>>n;
        mergesort(arr,0,n-1);
        for(int i=0;i<=n-1;i++)
    {
       cout<<arr[i];
    }
    return 0;
}