// Greedy Algorithm to find minimum number of coin
#include <bits/stdc++.h>
using namespace std;
vector<int> minCoins(int V)
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        while(V>=coins[i])
        {
            V-=coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}
int main()
{
    int V = 17385;
    vector<int> ans = minCoins(V);
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int coin : ans)
    {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}