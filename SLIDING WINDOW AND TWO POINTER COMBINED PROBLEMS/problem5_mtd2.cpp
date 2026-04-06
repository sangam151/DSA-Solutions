// Binary subarray with sum using better approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> prefixSumCount;
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;
        for (int num : nums)
        {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end())
            {
                count += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }
        return count;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << obj.numSubarrayWithSum(nums, goal) << endl;
    return 0;
}
