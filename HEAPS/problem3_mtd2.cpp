// Kth largest or smallest element in an array by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthLargestElement(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
int main()
{
    vector<int> nums = {-5, 4, 1, 2, -3};
    int k = 5;

    // Creating an object of the Solution class
    Solution sol;

    // Function call to get the Kth largest element
    int ans = sol.kthLargestElement(nums, k);

    // Output array
    cout << "The Kth largest element in the array is: " << ans << endl;

    return 0;
}