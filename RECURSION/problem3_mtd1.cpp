#include<iostream>
using namespace std;
void function(int i,int n)
{
    if(i<1) return;
    cout<<i<<endl;
    function(i-1,n);
}
int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    cout<<"printing"<<endl;
    function(n,n);
    return 0;
}