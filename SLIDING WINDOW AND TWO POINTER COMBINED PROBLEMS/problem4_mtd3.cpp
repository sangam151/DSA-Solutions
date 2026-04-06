// Longest repeating character replacement by optimal approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26, 0);
        int left = 0, right = 0, maxCount = 0, maxLength = 0;
        while (right < s.size())
        {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
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