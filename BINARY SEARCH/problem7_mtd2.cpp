// last occurance in the sorted array by optimal approach(binary search approach)
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int key, vector<int> v)
{
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(v[mid]==key)
        {
            start=mid+1;
            res=mid;
        }
        else if(v[mid]>key)
        {
            end=mid-1;
        }
        else start=mid+1;
    }
    return res;
}
using namespace std;
int main()
{
    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    cout << solve(n, key, v) << endl;
    return 0;
}