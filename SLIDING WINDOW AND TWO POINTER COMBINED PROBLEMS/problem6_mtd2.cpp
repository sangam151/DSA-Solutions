// count the number of nice subarrays
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int oddCount = 0;
        int result = 0;
        for (int num : nums)
        {
            if (num % 2 == 1)
                oddCount++;
            if (freq.count(oddCount - k))
            {
                result += freq[oddCount - k];
            }
            freq[oddCount]++;
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}