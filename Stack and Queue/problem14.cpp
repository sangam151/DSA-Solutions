//Next Greater ELement using stack
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreater(vector<int> &nums)
    {
        // stack to store element
        stack<int> st;
        // Result array of same size
        int n = nums.size();
        vector<int> res(n);
        // Transverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // pop all smaller or equal element
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            // if stack is empty no element
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(nums[i]);
        }
        return res;
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