// Minimum insertion/deletion to convert string s1 to s2
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        int lcs = dp[n][m];
        return (n - lcs) + (m - lcs);
    }
};
int main()
{
    Solution sol;
    string s1 = "heap", s2 = "pea";
    cout << "Minimum Operations: " << sol.minOperations(s1, s2) << endl;
    return 0;
}