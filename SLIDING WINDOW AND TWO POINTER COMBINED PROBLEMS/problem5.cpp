// Binary subarray with sum using brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayWithSum(vector<int> &nums, int goal)
    {
        int count = 0;
        for (int start = 0; start < nums.size(); start++)
        {
            int sum = 0;
            for (int end = start; end < nums.size(); end++)
            {
                sum += nums[end];
                if (sum == goal)
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
    Solution obj;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << obj.numSubarrayWithSum(nums, goal) << endl;
    return 0;
}
