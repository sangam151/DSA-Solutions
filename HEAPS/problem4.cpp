// sort k sorted array
#include <bits/stdc++.h>
using namespace std;
vector<int> findKSortedArray(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)
        {
            nums[i - k - 1] = pq.top();
            pq.pop();
        }
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        nums[i] = pq.top();
        pq.pop();
    }
    return nums;
}
int main()
{
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> ans = findKSortedArray(nums, k);
    cout << "Sorted array is \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}