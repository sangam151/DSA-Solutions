//Find the lowest and highest frequency element in the array
#include<bits/stdc++.h>
using namespace std;
void Frequency(int arr[],int n)
{
    int maxfrequency=0,minfrequency=n;
    int maxelement=0,minelement=0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        map[arr[i]]++;

    }
    for(auto it:map)
    {
        int count=it.second;
        int element=it.first;
        if(count>maxfrequency)
        {
        maxfrequency=count;
        maxelement=element; 
        }
        if(count<minfrequency)
        {
            minfrequency=count;
            minelement=element;
        }

    }
    cout<<"The highest frequency Element is "<<maxelement <<" with frequency "<<maxfrequency<<endl;
    cout<<"The Lowest frequency Element is "<<minelement <<" with frequency "<<minfrequency<<endl;
   
}
int main(){
    int arr[]={1,2,3,4,1,1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    Frequency(arr,n);

    return 0;
}