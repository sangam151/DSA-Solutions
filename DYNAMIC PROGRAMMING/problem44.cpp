// Wild card matching by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAllStars(string &s1, int i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (s1[j] != '*')
                return false;
        }
        return true;
    }
    bool wildCardMatchingUtil(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
            return isAllStars(s1, i);
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j] || s1[i] == '?')
        {
            return dp[i][j] = wildCardMatchingUtil(s1, s2, i - 1, j - 1, dp);
        }
        if (s1[i] == '*')
        {
            return dp[i][j] = wildCardMatchingUtil(s1, s2, i - 1, j, dp) || wildCardMatchingUtil(s1, s2, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }
    bool wildcardMatching(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return wildCardMatchingUtil(s1, s2, n - 1, m - 1, dp);
    }
};
int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";
    Solution obj;
    if (obj.wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}
