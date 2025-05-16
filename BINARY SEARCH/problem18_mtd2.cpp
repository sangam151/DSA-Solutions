/*Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages
from one port to another. The packages must be shipped within 'd' days.The weights of the packages
are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the
same order as they appear in the array. The loaded weights must not exceed the maximum weight
capacity of the ship.Find out the least-weight capacity so that you can ship all the packages within
'd' days.(optimal approach by using binary search)*/
#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> arr, int leastweight,int days)
{
    int n = arr.size(), sum = 0,cnt=0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if(sum>leastweight)
        {
            cnt++;
            sum=arr[i];
        }
    }
    cnt++;
    return cnt<=days;
}
int least_weight_capacity(vector<int> arr, int d)
{
    int n = arr.size();
    int maxi = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum = sum + arr[i];
    }
    int low=maxi,high=sum;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(possible(arr,mid,d))
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
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int d = 1;
    int ans = least_weight_capacity(arr, d);
    cout << "least capacity of the ship is " << ans << endl;
    return 0;
}