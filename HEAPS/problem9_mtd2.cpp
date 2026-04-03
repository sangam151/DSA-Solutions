// Replace elementsby its rank in the array by optimal approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr)
    {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr)
        {
            if (rankMap.find(num) == rankMap.end())
            {
                rankMap[num] = rank;
                rank++;
            }
        }
        vector<int> result;
        for (int num : arr)
        {
            result.push_back(rankMap[num]);
        }
        return result;
    }
};
int main()
{
    vector<int> arr = {1, 5, 8, 15, 8, 25, 9};
    Solution sol;
    vector<int> result = sol.replaceWithRank(arr);

    for (int r : result)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}