//minimum days to make M bouquets
#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> arr, int day, int m, int k)
{
    int n = arr.size();
    int noOfB = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> arr, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n)
        return -1; // impossible case
    // find maximum and minimum
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    int low=mini,high=maxi;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(possible(arr,mid,m,k))
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       

    }
     return low;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int N = 8;
    int m = 2, k = 3;
    int ans = roseGarden(arr, m, k);
    if (ans == -1)
    {
        cout << "We cannot make " << m << " bouquet";
    }
    else
    {
        cout << "The minimum days to make " << m << " bouquet is: " << ans << endl;
    }
    return 0;
}