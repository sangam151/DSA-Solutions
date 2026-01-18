// Partition set into 2 subset with minimum absolute sum difference by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        k += arr[i];
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = prev[target - arr[ind]];
            }
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    int mini = 1e9;
    for (int i = 0; i <= k; i++)
    {
        if (prev[i])
        {
            int diff = abs(i - (k - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << "The minimum absolute difference is" << minSubsetSumDifference(arr, n);
    return 0;
}