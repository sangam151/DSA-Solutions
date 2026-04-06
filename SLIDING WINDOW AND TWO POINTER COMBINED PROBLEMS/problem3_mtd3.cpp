// Fruit into basket by optimal approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int maxLen = 0;
        int lastFruit = -1, secondLastFruit = -1;
        int currentCount = 0, lastfruitstreak = 0;
        for (int fruit : fruits)
        {
            if (fruit == lastFruit || fruit == secondLastFruit)
            {
                currentCount++;
            }
            else
            {
                currentCount = lastfruitstreak + 1;
            }
            if (fruit == lastFruit)
            {
                lastfruitstreak++;
            }
            else
            {
                lastfruitstreak = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            maxLen = max(maxLen, currentCount);
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    vector<int> fruits = {1, 2, 1};
    cout << obj.totalFruit(fruits) << endl;
    return 0;
}