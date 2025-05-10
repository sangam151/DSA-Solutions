// search element in the rotated sorted array
#include <bits/stdc++.h>
using namespace std;
int search(vector<int> arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if mid points to the target
        if (arr[mid] == k)
            return mid;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element if exist
                high = mid - 1;
            }
            else
            {
                // element does not exist
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted
            if(arr[mid]<=k && k<=arr[high])
            {
                //element if exist
                low=mid+1;
            }
            else
            {
                //element if doesnot exist
                high=mid-1;

            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not available" << endl;
    else
        cout << "Target is: " << ans;
}