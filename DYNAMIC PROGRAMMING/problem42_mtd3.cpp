// Distinct subsequence by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<long long> dp(m + 1, 0);
        dp[m] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            vector<long long> curr = dp;
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    curr[j] = dp[j + 1] + dp[j];
                }
                else
                {
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }
        return (int)dp[0];
    }
};
int main()
{
    Solution sol;
    string s = "babgbag";
    string t = "bag";
    cout << sol.numDistinct(s, t) << endl;
    return 0;
}