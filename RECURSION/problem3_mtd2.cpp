#include<iostream>
using namespace std;
void function(int i,int n)
{
    if(i>n) return;
    function(i+1,n);
    cout<<i;
}
int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    function(1,n);
    return 0;
}