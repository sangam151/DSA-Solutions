// Area of largest rectangle in histogram by brute force approach
#include <bits/stdc++.h>
using namespace std;
int largestArea(int arr[], int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3, 1};
    int n = 7;
    cout << "The largest area in the histogram is " << largestArea(arr, n) << endl;
    return 0;
}
