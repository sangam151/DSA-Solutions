/*Buy and Sell stock by memoization approach
Problem Statement:

Buy and Sell Stock - II

We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days.
The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it.
After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously
bought stock.*/
#include <bits/stdc++.h>
using namespace std;
class StockProfit
{
    long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        long profit = 0;
        if (buy == 0) // buy the stock
        {
            profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
        }
        if (buy == 1) // sell the stock
        {
            profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    long getMaximumProfit(long *Arr, int n)
    {
        vector<vector<long>> dp(n, vector<long>(2, -1));
        if (n == 0)
            return 0;
        long ans = getAns(Arr, 0, 0, n, dp);
        return ans;
    }
};
int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};
    StockProfit sol;
    cout << "maximum profit after buy and sell stock is: " << sol.getMaximumProfit(Arr, n);
    return 0;
}