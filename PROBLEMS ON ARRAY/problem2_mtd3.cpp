#include<bits/stdc++.h>
using namespace std;
int second_largest(int arr[],int n)
{
int largest=arr[0];
int secondlargest=INT_MIN;
for(int i=0;i<n;i++)
{
if(arr[i]>largest)
{

secondlargest=largest;
largest=arr[i];
}
else if(arr[i]!=largest && arr[i]>secondlargest)
{
    secondlargest=arr[i];
}
}
return secondlargest;
}
int second_smallest(int arr[],int n)
{
int smallest=arr[0];
int secondsmallest=INT_MAX;
for(int i=0;i<n;i++)
{
    if(arr[i]<smallest)
    {
        secondsmallest=smallest;
        smallest=arr[i];

    }
    else if(arr[i]!=smallest && arr[i]<secondsmallest)
    {
    secondsmallest=arr[i];
    }
    
}
return secondsmallest;
}
int main(){
    int arr[]={3,4,5,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sl=second_largest(arr,n);
    int ss=second_smallest(arr,n);
    cout<<"the second largest element of the array is "<<sl<<endl;
    cout<<"the second smallest element of the array is "<<ss<<endl;

    return 0;
}