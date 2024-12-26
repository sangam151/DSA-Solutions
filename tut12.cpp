#include<iostream>
using namespace std;
void sangam(int n)
{
    for(int i=0;i<n;i++)//n=4
 {
    for(int j=n;j>=n-i;j--)
    {
        cout<<j;
    }
    for(int k=0;k<(2*n)-3-(2*i);k++)
    {
        cout<<n-i;
    }
    int z=n;
    if(n-1==i)
    {
        z=n;
       for(int x=n;x>=n-i+1;x--) 
        {
       
       cout<<z-i+1;
        z++;
    }
    }
    else{
    for(int x=n;x>=n-i;x--)
    {
       
       cout<<z-i;
        z++;
    }}
    cout<<endl;
 }
 
}
void poudel(int n)
{
    int j,i;
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
    cout<<n-j;
    }
for(int k=0;k<(2*i)+1;k++)
{
cout<<i+2;
}
int z=i+1;
for(int x=0;x<n-i-1;x++)
{
    z++;
    cout<<z;
    
}
cout<<endl;
}
}
int main(){
    int n;
    cout<<"enter the value of n";
    cin>>n;
 sangam(n);
 poudel(n);
    return 0;
}