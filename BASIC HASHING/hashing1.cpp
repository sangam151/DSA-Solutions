//Number Hashing
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int arr[n];
    cout<<"input the array element"<<endl;
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }
    int hash[13]={0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]+=1;
    }
    cout<<"enter the queries"<<endl;
    int q;
    cin>>q;
    cout<<"printing"<<endl; 
    while(q--)
    {
        int number;
        cin>>number;
        
        cout<<hash[number]<<endl;
    }

    return 0;
}