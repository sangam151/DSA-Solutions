// maximum point you can obtain from cards by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxSum = 0;
        for (int i = 0; i <= k; i++)
        {
            int tempSum = 0;
            for (int j = 0; j < i; j++)
            {
                tempSum += cardPoints[j];
            }
            for (int j = 0; j < k - i; j++)
            {
                tempSum += cardPoints[n - 1 - j];
            }
            maxSum = max(maxSum, tempSum);
        }
        return maxSum;
    }
};
int main()
{
    Solution sol;
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << sol.maxScore(cards, k) << endl;
    return 0;
}