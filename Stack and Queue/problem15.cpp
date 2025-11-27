// Next Greater Element -2 (circular array)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreater(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int ind = i % n;
            int currEle = nums[ind];
            while (!st.empty() && st.top() <= currEle)
            {
                st.pop();
            }
            if (i < n)
            {
                if (st.empty())

                    ans[i] = -1;

                else
                    ans[i] = st.top();
            }

            st.push(currEle);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {4, 5, 2, 10};
    Solution sol;
    vector<int> ans = sol.nextGreater(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}
