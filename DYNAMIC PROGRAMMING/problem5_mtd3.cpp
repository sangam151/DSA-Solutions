// maximum sum of Non Adjacent elements by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumAdjacentSum(vector<int> &arr)
    {
        int prev2 = 0;
        int prev = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            int include = arr[i] + prev2;
            int exclude = prev;
            int curr = max(include, exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;
    cout << obj.maximumAdjacentSum(arr);
    return 0;
}