// Minimum Window Subsequence
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    int minLen = INT_MAX;
    string result = "";
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (i < n)
        {
            if (s[i] == t[j])
            {
                j++;
                if (j == m)
                    break;
            }
            i++;
        }
        if (j < m)
            break;
        int end = i;
        j = m - 1;
        while (i >= 0)
        {
            if (s[i] == t[j])
            {
                j--;
                if (j < 0)
                    break;
            }
            i--;
        }
        int start = i;
        if (end - start + 1 < minLen)
        {
            minLen = end - start + 1;
            result = s.substr(start, minLen);
        }
        i = start + 1;
    }
    return result;
}
int main()
{
    string s = "abcdebdde";
    string t = "bde";
    cout << minWindow(s, t) << endl;
    return 0;
}