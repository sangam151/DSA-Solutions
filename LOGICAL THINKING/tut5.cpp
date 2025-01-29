#include<iostream>
using namespace std;
void nStarDiamond(int n) {
    int x=0;
   for(int i=0;i<(2*n);i++)//n=2
   {
       if(i<=(n-1))
       {
         for (int j = 0; j < n - (i + 1); j++) {
           cout << " ";
         }
         for (int k=0;k<(2*i)+1;k++)
         {
             cout<<"*";
         }
          cout<<endl;
       }
      
       else{
           
for(int j=0;j<((2*n)-1)-(2*x);j++)
{
    cout<<"*";
}
x++;
cout<<endl;
for(int k=0;k<x;k++)
{
    cout<<" ";
}

       }
   }
}

int main(){
     int n = 4; // Change this to test different sizes
    nStarDiamond(n);
   
    return 0;
}