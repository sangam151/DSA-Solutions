// wildcard matching using tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAllStars(string &s1, int i)
    {
        for (int j = 1; j <= i; j++)
        {
            if (s1[j - 1] != '*')
                return false;
        }
        return true;
    }
    bool wildCardMatching(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = isAllStars(s1, i);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (s1[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";
    Solution obj;
    if (obj.wildCardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}