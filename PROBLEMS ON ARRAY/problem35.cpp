//count the number of inversion by brute force approach
#include<bits/stdc++.h>
using namespace std;
int countInversion(vector<int> a)
{
    int n=a.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<int> a={5,4,3,2,1};
    int cnt=countInversion(a);
    cout<<"The number of inversion in the given array is:"<<cnt<<endl;
    return 0;

}