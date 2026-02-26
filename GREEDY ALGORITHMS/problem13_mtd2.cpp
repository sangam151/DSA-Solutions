// Merge Overlapping Sub-intervals
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (auto interval : intervals)
        {
            if (ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    for (auto interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "]";
    }
    return 0;
}