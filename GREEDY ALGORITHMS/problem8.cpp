//Jump Game II ||By Greedy Approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 1, 2, 1, 1, 1, 1};
    cout << "Minimum jumps required: " << sol.jump(nums) << endl;
    return 0;
}