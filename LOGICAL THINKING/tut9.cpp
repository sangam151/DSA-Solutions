#include<iostream>
using namespace std;
void sangam(int n)
{
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
    {
        cout<<"*";
    }
    if(i>1)
    
    {
        for(int x=1;x<=(2*i)-2;x++)
        {
            cout<<" ";
        }
    }
   
    for(int k=n;k>=i;k--)//n=5
    {
        cout<<"*";
    }
    cout<<endl;
    }
}
void poudel(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        
        {
            cout<<"*";
        }
        for(int k=1;k<=(2*n)-(2*i);k++)
        {
            cout<<" ";
        }
        for(int x=1;x<=i;x++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
}
int main(){
      int n;
    cout<<"enter a number";
    cin>>n;
   sangam(n);
   poudel(n);
    return 0;
}