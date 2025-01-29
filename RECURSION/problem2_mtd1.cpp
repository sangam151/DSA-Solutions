//print 1 to N using recursion
#include<iostream>
using namespace std;
void function(int i,int n)
{
   if(i>n) return;
   cout<<i<<endl;
   function(i+1,n);
}
int main(){
    int n;//n=3
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"1 to N using recursion"<<endl;
    function(1,n);
    return 0;
}