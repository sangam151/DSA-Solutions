//split array-largest sum   
#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> arr, int mPages, int m)
{
    int n = arr.size();
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum > mPages)
        {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt;
}
int largestSubarraySumMinimized(vector<int> arr, int m)
{
    int n = arr.size(); // number of books
    int maxi = INT_MIN;
    int sum = 0;
    if (m > n)
        return -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum = sum + arr[i];
    }
    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt=possible(arr,mid,m);
        if (cnt>m)
        {
            low=mid+1;

        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {10,20,30,40};
    int k = 2; // number of student
    int ans = largestSubarraySumMinimized(arr, k);
    cout << "The answer is: " << ans << endl;
    return 0;
}