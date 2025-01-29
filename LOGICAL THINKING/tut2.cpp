#include<iostream>
using namespace std;

int main(){
    int i,j,k,z=-1,n;
    cout<<"number of rows";
    cin>>n;
    for(i=n;i>=0;i--)
    {
    z++;
        for(k=0;k<=i;k++)
        {
            cout<<" ";
        }
        for(j=1;j<=(2*z)+1;j++)
        {
           cout<<"*";
        }
      cout<<"\n";
    }
    return 0;
}