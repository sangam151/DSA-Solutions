// Printing Longest increasing subsequence
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> longestIncreasingSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        vector<int> lisSeq;
        int curr = maxIndex;
        while (curr != -1)
        {
            lisSeq.push_back(nums[curr]);
            curr = prev[curr];
        }
        reverse(lisSeq.begin(), lisSeq.end());
        return lisSeq;
    }
};
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(nums);
    cout << "LIS: ";
    for (int x : lis)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}