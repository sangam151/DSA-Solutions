#include<iostream>
using namespace std;
int function(int n)
{
     if(n==0)
     {
        return 0;
     }
    return n+function(n-1);
}
int main(){
    int n;
    cin>>n;
    function(n);
    return 0;
}