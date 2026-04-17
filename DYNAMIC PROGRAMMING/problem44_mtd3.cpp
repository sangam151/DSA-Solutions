// wildcard matching using tabulation space optimized approach
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
        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++)
        {
            cur[0] = isAllStars(s1, i);
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (s1[i - 1] == '*')
                {
                    cur[j] = prev[j] || cur[j - 1];
                }
                else
                    cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
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