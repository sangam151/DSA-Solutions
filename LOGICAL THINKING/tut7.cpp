#include<iostream>
using namespace std;

int main(){
    cout<<"enter the value of n";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        cout<<"  ";
         for(char k='A';k<='A'+i;k++)
    {
        cout<<k<<" ";
    }
    if(i>0)
    {
    for(char x='A'+i-1;x>='A';x--)
    {
        cout<<x<<" ";
    }
    }
    cout<<endl;
    }
   
    
    return 0;
}
