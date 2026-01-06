/*CANDY by Brute force approach
A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.
These kids are receiving candy according to the following criteria:

There must be at least one candy for every child.
Kids whose scores are higher than their neighbours receive more candies than their neighbours.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);
        bool updated = true;
        while (updated)
        {
            updated = false;
            for (int i = 1; i < n; i++)
            {
                if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
                {
                    candies[i] = candies[i - 1] + 1;
                    updated = true;
                }
            }
            for (int i = n - 2; i >= 0; i--)
            {
                if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i + 1])
                {
                    candies[i] = candies[i + 1] + 1;
                    updated = true;
                }
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
int main()
{
    Solution obj;
    vector<int> ratings = {1, 0, 5};
    cout << "minimum candies required: " << obj.candy(ratings) << endl;
    return 0;
}
