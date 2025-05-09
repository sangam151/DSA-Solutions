// peak element in the array by brute force approach
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // checking for the peak
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i + 1] < arr[i]))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak element is at index: " << ans << endl;
}