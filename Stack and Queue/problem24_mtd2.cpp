// Stock span problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> findPGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int currEle = arr[i];
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

public:
    vector<int> stockSpan(vector<int> &arr, int n)
    {
        vector<int> PGE = findPGEE(arr);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = i - PGE[i];
        }
        return ans;
    }
};
int main()
{
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    Solution sol;
    vector<int> ans = sol.stockSpan(arr, n);
    cout << "The span of stock prices is: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}