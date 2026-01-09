// frog jump problem by tabulation space optimization approach || DP problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int frogJump(const vector<int> &height)
    {
        if (height.empty())
            return 0;
        int n = (int)height.size();
        vector<int> dp(n, INT_MAX);
        if (n == 1)
            return 0;
        int prev = 0;
        int prev2 = 0;

        for (int ind = 1; ind < n; ind++)
        {
            int jumpOne = prev + abs(height[ind] - height[ind - 1]);
            int jumpTwo = INT_MAX;
            if (ind > 1)
                jumpTwo = prev2 + abs(height[ind] - height[ind - 1]);
            int cur_i = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};
int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    Solution sol;
    cout << sol.frogJump(height) << endl;
    return 0;
}