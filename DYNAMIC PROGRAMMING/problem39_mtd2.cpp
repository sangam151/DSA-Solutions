// Longest palindromic subsequence
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int func(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                {
                    cur[ind2] = 1 + prev[ind2 - 1];
                }
                else
                {
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }

public:
    int longestPalinSubseq(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        return func(s, t);
    }
};
int main()
{
    string s = "bbabcbcab";
    Solution sol;
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalinSubseq(s);
    return 0;
}