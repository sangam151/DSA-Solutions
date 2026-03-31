// maximum sum combination using brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> allSums;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                allSums.push_back(nums1[i] + nums2[j]);
            }
        }
        sort(allSums.begin(), allSums.end(), greater<int>());
        vector<int> result(allSums.begin(), allSums.begin() + k);
        return result;
    }
};
int main()
{
    Solution obj;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = obj.maxCombinations(nums1, nums2, k);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
