// Fruit into basket by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int maxFruits = 0;
        for (int start = 0; start < fruits.size(); start++)
        {
            unordered_map<int, int> basket;
            int currentCount = 0;
            for (int end = start; end < fruits.size(); end++)
            {
                basket[fruits[end]]++;
                if (basket.size() > 2)
                {
                    break;
                }
                currentCount++;
            }
            maxFruits = max(maxFruits, currentCount);
        }
        return maxFruits;
    }
};
int main()
{
    Solution obj;
    vector<int> fruits = {1, 2, 1};
    cout << obj.totalFruit(fruits) << endl;
    return 0;
}