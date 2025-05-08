// lower bound by optimal approach
#include <bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerbound(arr, n, x);
    cout << "The lower bound is at index: " << ind << "\n";
    return 0;
}