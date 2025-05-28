//count the maximum number of one's by brute force approach
#include<bits/stdc++.h>
using namespace std;
int maximum_Ones(vector<vector<int>> arr)
{
    int n1=arr.size(),n2=arr[0].size();
    map<int,int> mpp;
    int maxi=INT_MIN;
    int maxindex=INT_MIN;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(arr[i][j]==1)
            mpp[i]++;
        }
        if(mpp[i]>maxi)
        {
            maxi=mpp[i];
            maxindex=i;
        }
    }
    return maxindex;

}
int main()
{
    vector<vector<int>> arr={{1,1,1},{0,0,1},{0,0,0}};
    cout<<"The row with maximum number of one's is "<<maximum_Ones(arr)<<endl;
    return 0;
}