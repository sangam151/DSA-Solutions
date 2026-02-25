// celebrity problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();
        vector<int> knowMe(n, 0);
        vector<int> iknow(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    knowMe[j]++;
                    iknow[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (knowMe[i] == n - 1 && iknow[i] == 0)
                return i;
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}};
    Solution sol;
    int ans = sol.celebrity(M);
    cout << "The index of celebrity is: " << ans;
    return 0;
}