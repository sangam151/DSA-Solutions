// Stock span problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> stockSpan(vector<int> &arr, int n)
    {
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int currSpan = 0;
            for (int j = i; j >= 0; j--)
            {
                if (arr[j] <= arr[i])
                {
                    currSpan++;
                }
                else
                    break;
            }
            ans[i] = currSpan;
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