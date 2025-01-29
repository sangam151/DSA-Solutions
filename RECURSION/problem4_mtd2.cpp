#include<iostream>
using namespace std;
void f(int i,int sum)
{
    if(i<1)
    {
        cout<<"the sum is"<<sum<<endl;
        return;
    }
    f(i-1,sum+i);

}
int main(){
    int n;
    cout<<"enter the n"<<endl;
    cin>>n;
    f(n,0);
    return 0;
}