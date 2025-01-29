#include<iostream>
using namespace std;
int sangam(int z)
{
    if(z==1||z==0)
    return 1;
    else
    return z*sangam(z-1);
}
int main(){
    int n,i,j,k;
    cout<<"enter the number of rows";
    cin>>n;//n=5
    n++;
    for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            cout<<" ";
        }
       
        for(k=0;k<i;k++)
        {
            cout<<sangam(i-1)/((sangam((i-1)-k))*(sangam(k)))<<" ";
           
        }
        cout<<endl;
    }
    return 0;
}