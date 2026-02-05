// partition array for maximum sum front partition by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = (int)arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int maxElem = 0;
            int maxSum = 0;
            for (int length = 1; length <= k && i + length <= n; length++)
            {

                maxElem = max(maxElem, arr[i + length - 1]);
                int currentSum = maxElem * length + dp[i + length];
                maxSum = max(maxSum, currentSum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};
int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    Solution sol;
    cout << "Maximum sum after partitioning" << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}