// minimum path sum in traingular grid by tabulation space optimized approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int minimumPathSum(vector<vector<int>> &traingle, int n)
    {
        vector<int> front(n, 0);
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            front[j] = traingle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = traingle[i][j] + front[j];
                int diag = traingle[i][j] + front[j + 1];
                cur[j] = min(down, diag);
            }
            front = cur;
        }
        return front[0];
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> traingle{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    int n = traingle.size();
    cout << obj.minimumPathSum(traingle, n);
    return 0;
}