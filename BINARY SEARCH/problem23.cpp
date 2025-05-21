/*You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the
X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them
anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the
distance between adjacent gas stations after adding k new gas stations.
Find the minimum value of ‘dist’.(by brute force approach)*/
#include<bits/stdc++.h>
using namespace std;
long double minimizeDistance(vector<int> arr,int k)
{
    int n=arr.size();//size of the array
    vector<int> howMany(n-1,0);
    //pick and place n gas station
    for(int gasStations=1;gasStations<=k;gasStations++)
    {
        //find the maximum station
        //and insert the gas station
        long double maxSection=-1;
        int maxInd=-1;
        for(int i=0;i<n-1;i++)
        {
            long double diff=arr[i+1]-arr[i];
            long double sectionLength=diff/(long double)(howMany[i]+1);
            if(sectionLength>maxSection)
            {
                maxSection=sectionLength;
                maxInd=i;
            }
        }
        //insert the current gas station
        howMany[maxInd]++;  
    }
    long double maxAns=-1;
    for(int i=0;i<n-1;i++)
    {
        long double diff=arr[i+1]-arr[i];
        long double sectionLength=diff/(long double)(howMany[i]+1);
        maxAns=max(maxAns,sectionLength);
    }
    return maxAns;

}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int k=4;
    long double ans=minimizeDistance(arr,k);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}