#include<bits/stdc++.h>
using namespace std;
void Frequency(int arr[],int n)
{
    vector<bool> visited(n,false);
    int maxfrequency=0,minfrequency=n;
    int maxelement=0,minelement=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true)
        continue;
         int count=1;
        for(int j=i+1;j<n;j++)
        {
           
            if(arr[i]==arr[j])
            {
                visited[j]=true;
                count++;

            }
        }
        if(count>maxfrequency)
        {
            maxfrequency=count;
            maxelement=arr[i];
        }
        if(count<minfrequency)
        {
            minfrequency=count;
            minelement=arr[i];
        }
    }
    cout<<"the highest frequency element is "<<maxelement<<endl;
    cout<<"the smallest frequency element is "<<minelement<<endl;
}
int main(){
    int arr[]={1,2,3,4,4,4,4,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    Frequency(arr,n);
    return 0;
}