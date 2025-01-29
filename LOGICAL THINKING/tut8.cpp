#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cout<<"enter a number";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(char j='E'-i;j<='E';j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
}
    return 0;
}