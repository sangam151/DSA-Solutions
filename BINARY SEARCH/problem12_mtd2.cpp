//Find out how many times the array has been rotated by optimal approach
#include <bits/stdc++.h>
using namespace std;
int minSorted(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MAX;
    int low = 0;
    int high = n - 1;
    int index=-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[low]<arr[high])
        {
            ans=min(ans,arr[low]);
            index=low;
            break;
        }
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            index=low;
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            index=mid;
            high=mid-1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = minSorted(arr);
    cout<<"The array is rotated "<<ans<<" times"<<endl;
    return 0;
}