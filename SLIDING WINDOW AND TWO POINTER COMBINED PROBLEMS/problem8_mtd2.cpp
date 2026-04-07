// maximum point you can obtain from cards by optimal approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < k; i++)
        {
            total += cardPoints[i];
        }
        int maxPoints = total;
        for (int i = 0; i < k; i++)
        {
            total -= cardPoints[k - 1 - i];
            total += cardPoints[n - 1 - i];
            maxPoints = max(maxPoints, total);
        }
        return maxPoints;
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