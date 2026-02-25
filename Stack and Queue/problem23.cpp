// Sliding window maximum by brute force approach
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMax(vector<int> &arr, int k)
{
    vector<int> arr1;
    for (int i = 0; i < arr.size(); i++)
    {
        int maxi = 0;
        if (i == arr.size() - 2)
            break;
        else
        {
            for (int j = i; j < i + 3; j++)
            {
                maxi = max(maxi, arr[j]);
            }
            arr1.push_back(maxi);
        }
    }
    return arr1;
}
int main()
{
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;
    vector<int> ans = slidingWindowMax(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
