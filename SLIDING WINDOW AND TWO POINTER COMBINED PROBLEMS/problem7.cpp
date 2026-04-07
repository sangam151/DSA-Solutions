// Number of substring containing all three character
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberofSubstring(string s)
    {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    string s = "abcabc";
    cout << sol.numberofSubstring(s) << endl;
    return 0;
}