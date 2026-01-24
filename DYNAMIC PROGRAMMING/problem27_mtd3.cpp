// unbounded Knapsack problem  by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
    {
        vector<int> cur(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            cur[i] = (i / wt[0]) * val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int cap = 0; cap <= W; cap++)
            {
                int notTaken = cur[cap];
                int taken = INT_MIN;
                if (wt[ind] <= cap)
                {
                    taken = val[ind] + cur[cap - wt[ind]];
                }
                cur[cap] = max(taken, notTaken);
            }
        }
        return cur[W];
    }
};
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    Solution obj;
    cout << "The maximum value of items the thief can steal is: " << obj.unboundedKnapsack(n, W, val, wt) << endl;
}