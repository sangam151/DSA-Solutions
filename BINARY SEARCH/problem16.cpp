/*KoKo Eating Bananas
problem statement:A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas.An
integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.Each hour,
the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’
bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within
‘h’ hours.*/
#include <bits/stdc++.h>
using namespace std;
int findMaxi(vector<int> &v)
{
    int n = v.size();
    int maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> & v,int hourly)
{
     int totalH = 0;
     int n=v.size();
        for (int i = 0; i < n; i++)
        {
            totalH+=ceil((double)(v[i])/(double)(hourly));
        }
        return totalH;
}
int minimumRateToEatBananas(vector<int> &v, int h)
{
    int maxi = findMaxi(v);
    int N = v.size();
    for (int i = 1; i <= maxi; i++)
    {
        int ans=calculateTotalHours(v,i);
        if (ans<= h)
            return i;
    }
    return maxi;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "KoKo should eat atleast " << ans << " bananas/hr." << endl;
    return 0;
}