#include<iostream>
using namespace std;
void function(int i,int n)
{
    if(i<1) return;
     function(i-1,n);
     cout<<i<<endl;
}
int main(){
    int n;//n=5
    cout<<"enter a n"<<endl;
    cin>>n;
    cout<<"printing"<<endl;
    function(n,n);//(5,5)

    return 0;
}