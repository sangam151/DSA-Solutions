// Palindrome partitioning by memoization approach
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
    int minCutHelper(const string &s, int start, vector<int> &memo)
    {
        int n = (int)s.size();
        if (start == n || isPalindrome(s, start, n - 1))
            return 0;
        if (memo[start] != -1)
            return memo[start];
        int minCuts = INT_MAX;
        for (int end = start; end < n; end++)
        {
            if (isPalindrome(s, start, end))
            {
                int cuts = 1 + minCutHelper(s, end + 1, memo);
                minCuts = min(minCuts, cuts);
            }
        }
        return memo[start] = minCuts;
    }

public:
    int minCut(string s)
    {
        int n = (int)s.size();
        vector<int> memo(n, -1);
        return minCutHelper(s, 0, memo);
    }
};
int main()
{
    string s = "aab";
    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << endl;
    return 0;
}