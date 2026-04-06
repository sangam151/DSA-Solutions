// Longest repeating character replacement by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < s.length(); j++)
            {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                int windowLength = j - i + 1;
                int replace = windowLength - maxFreq;
                if (replace <= k)
                {
                    maxLength = max(maxLength, windowLength);
                }
            }
        }
        return maxLength;
    }
};
int main()
{
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}