/*Problem Statement:Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ 
into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is 
to return the minimized largest sum of the split.A subarray is a contiguous part of the array.*/
#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> arr, int mPages, int k)
{
    int n = arr.size();
    int sum = 0;
    int cnt=1;
    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
        if(sum>mPages)
        {
            cnt++;
            sum=arr[i];
        }
    }
    return cnt==k;
}
int largestSubarraySumMinimized(vector<int> arr, int k)
{
    int n = arr.size(); // number of books
    int maxi = INT_MIN;
    int sum = 0;
    if (k > n)
        return -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum = sum + arr[i];
    }
    for (int i = maxi; i <= sum; i++)
    {
        if (possible(arr, i, k))
            return i;
    }
    return maxi;
}
int main()
{
    vector<int> arr = {10,20,30,40};
    int k = 2; // number of student
    int ans = largestSubarraySumMinimized(arr, k);
    cout << "Maximum number of pages assigned to a student is minimum is: " << ans << endl;
    return 0;
}  