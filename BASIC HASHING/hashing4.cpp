//map hashing 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of element that you want to store"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the "<<i+1<<" number"<<endl;
        cin>>arr[i];
    }
    //pre compute
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;

    }
    //iterate in the map
    for(auto it:mpp)
    {
        cout<<it.first<<"-->"<<it.second<<endl;
    }
    int q;
    cout<<"enter the number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        cout<<"the number of times it appear is "<<mpp[number]<<endl;
    }
    return 0;
}