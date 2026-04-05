// Max Consecutive ones III by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int zeros = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == 0)
                {
                    zeros++;
                }
                if (zeros > k)
                    break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}