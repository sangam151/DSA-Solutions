/*Problem Statement:  You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  
denotes that the 'ith' rose will bloom on the 'arr[i]th' day.You can only pick already bloomed roses that 
are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to 
make a single bouquet.Find the minimum number of days required to make at least ‘m' bouquets each 
containing 'k' roses. Return -1 if it is not possible.*/ //(brute force approach)
#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> arr, int day, int m, int k)
{
    int n = arr.size();
    int noOfB = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> arr, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n)
        return -1; // impossible case
    // find maximum and minimum
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int N = 8;
    int m = 2, k = 3;
    int ans = roseGarden(arr, m, k);
    if (ans == -1)
    {
        cout << "We cannot make " << m << " bouquet";
    }
    else
    {
        cout << "The minimum days to make " << m << " bouquet is: " << ans << endl;
    }
    return 0;
}