// Sliding window maximum by optimal approach
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMax(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}
int main()
{
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;
    vector<int> ans = slidingWindowMax(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
