//KoKo eating bananas by binary search
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

    int low=1,high=findMaxi(v);
    
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        int totalH=calculateTotalHours(v,mid);
        if(totalH<=h)
        {
            
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }

    }
    return low;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "KoKo should eat atleast " << ans << " bananas/hr." << endl;
    return 0;
}