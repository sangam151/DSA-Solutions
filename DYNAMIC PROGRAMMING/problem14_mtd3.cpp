// Subset sum equal to target by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
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
};
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "subset with the given target found";
    else
        cout << "subset with the given target not found";
    return 0;
}