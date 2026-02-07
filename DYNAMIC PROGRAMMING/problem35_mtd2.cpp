// palindrome partitioning by tabulation approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isPalindrome(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

public:
    int minCut(string s)
    {
        int n = (int)s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int minCuts = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
};
int main()
{
    string s = "aab";
    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << endl;
    return 0;
}