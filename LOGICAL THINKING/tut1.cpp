#include<iostream>
using namespace std;

int main(){
    int i,j,k,z=0;
    for(i=3;i>=0;i--)
    {
        z++;
        for(j=1;j<=(2*i)+1;j++)
        
        {
            printf("*");
        }
        printf("\n");
        for(k=1;k<=z;k++)
        {
        printf(" ");
        }
    }
    return 0;
}