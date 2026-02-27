#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        return minJumps(nums, 0);
    }

private:
    int minJumps(vector<int> &nums, int position)
    {
        if (position >= nums.size() - 1)
            return 0;
        if (nums[position] == 0)
            return INT_MAX;
        int minStep = INT_MAX;
        for (int jump = 1; jump <= nums[position]; jump++)
        {
            int subResult = minJumps(nums, position + jump);
            if (subResult != INT_MAX)
            {
                minStep = min(minStep, 1 + subResult);
            }
        }
        return minStep;
    }
};
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    cout << "Minimum number of jumps: " << sol.jump(nums) << endl;
    return 0;
}