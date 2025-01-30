#include<bits/stdc++.h>

using namespace std;
int partition(vector<int> &arr,int low,int high)
{
     int pivot=arr[low];
     int i=low;
     int j=high;
     while(i<j)
     {
        while(arr[i]<=pivot &&i<=high-1)
        {
            i++;

        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }
          if(i<j) swap(arr[i],arr[j]);
     }
     swap(arr[low],arr[j]);
     return j; 
}
void quicksort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int pIndex=partition(arr,low,high);
        quicksort(arr,low,pIndex-1);
        quicksort(arr,pIndex+1,high);
    }
}
int main(){
    vector<int> arr{5,4,3,2,1};
    int n=arr.size();
    quicksort(arr,0,n-1);
 
    return 0;
}