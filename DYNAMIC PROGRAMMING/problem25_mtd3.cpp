// Minimum coin by space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &arr, int K)
    {
        int n = arr.size();
        vector<int> prev(K + 1, 0);
        vector<int> curr(K + 1, 0);
        for (int i = 0; i <= K; i++)
        {
            if (i % arr[0] == 0)
                prev[i] = i / arr[0];
            else
                prev[i] = 1e9;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= K; target++)
            {
                int notTake = prev[target];
                int take = 1e9;
                if (arr[ind] <= target)
                {
                    take = 1 + curr[target - arr[ind]];
                }
                curr[target] = min(notTake, take);
            }
            prev = curr;
        }
        int ans = prev[K];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}