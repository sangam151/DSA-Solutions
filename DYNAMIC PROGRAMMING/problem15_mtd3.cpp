// partition equal subset sum by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;

bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    if (totSum % 2 == 1)
        return false;
    int k = totSum / 2;
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
    return prev[k];
}
int main()
{
    vector<int> arr = {2, 2, 2, 2, 4, 4};
    int n = arr.size();
    if (canPartition(n, arr))
    {
        cout << "The Array can be partitioned into two equal parts" << endl;
    }
    else
        cout << "The Array cannot be partitioned into two equal parts" << endl;
    return 0;
}
