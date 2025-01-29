#include<iostream>
using namespace std;
int sum=0;
void function(int i,int n)
{
    if(i>n) return;
sum=sum+i;
function(i+1,n);

}
int main(){
    int n;
    cout<<"enter the n"<<endl;
    cin>>n;
    function(1,n);
    cout<<"the sum of N terms is"<<sum<<endl;
    return 0;
}