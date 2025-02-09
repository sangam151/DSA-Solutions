//Linear search in C
#include<bits/stdc++.h>
using namespace std;
int LinearSearch(int arr[],int n,int num)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    int num=3;
    int val= LinearSearch(arr,n,num);
    printf("%d is in index%d",num,val);
    return 0;
}