//Find the number that appears once, and the other numbers twice by brute force approach
#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> arr)
{
    //size of the array
    int n=arr.size();
    //for selecting the element
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        //find the occurance using linear search
        for(int j=0;j<n;j++)
        {
            if(arr[j]==arr[i])cnt++;
        }
        //if the occurance is 1
        if(cnt==1)return arr[i];

    }
   
}
int main(){
    vector<int> arr={4,1,2,1,2};
    int ans=getSingleElement(arr);
    cout<<"the number that appears once is "<<ans;
    return 0;
}