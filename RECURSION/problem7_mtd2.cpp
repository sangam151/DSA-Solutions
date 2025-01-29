#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    if(n==0)
    {
        cout<<"The fibonacci Series up to "<<n<<"th term:"<<endl;
        cout<<0;
    }
    else{
        int secondlast=0;
        int last=1;
           cout<<"The fibonacci Series up to "<<n<<"th term:"<<endl;
           cout<<secondlast<<" "<<last<<" ";
           int cur;
           for(int i=2;i<=n;i++)
           {
            cur=secondlast+last;
            secondlast=last;
            last=cur;
            cout<<cur<<" ";
           }
    }
}