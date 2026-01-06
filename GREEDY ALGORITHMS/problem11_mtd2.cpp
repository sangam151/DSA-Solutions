/*CANDY by Optimal Approach
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
        int candies = n;
        int i = 1;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                i++;
                continue;
            }
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                candies += peak;
                i++;
            }
            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                valley++;
                candies += valley;
                i++;
            }
            candies -= min(peak, valley);
            return candies;
        }
    }
};
int main()
{
    Solution obj;
    vector<int> ratings = {1, 0, 5};
    cout << "minimum candies required: " << obj.candy(ratings) << endl;
    return 0;
}
