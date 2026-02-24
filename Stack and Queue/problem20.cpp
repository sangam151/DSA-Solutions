// Sum of subarray ranges
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> arr)
    {
        int n = arr.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int smallest = arr[i];
            int largest = arr[i];
            for (int j = i; j < n; j++)
            {
                smallest = min(smallest, arr[j]);
                largest = max(largest, arr[j]);
                ans += (largest - smallest);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3};
    Solution sol;
    long long ans = sol.subArrayRanges(arr);
    cout << "The sum of subarray ranges is " << ans;
    return 0;
}