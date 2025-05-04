// find the count inversion in the array by optimal approach
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half array
    int right = mid + 1; // starting index of right half arrray
    //
    int cnt = 0; // to count the pairs
                 // storing element in the temporary array in a sorted manner
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    // if element on the left half are still left
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    // if element on the right half are still left
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    // transferring all the temporary array element to original array
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
    return cnt;
}
int mergeSort(vector<int> &a, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid + 1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}
int numberofInversions(vector<int> &a, int n)
{
    // count the number of pairs
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberofInversions(a, n);
    cout << "The number of inversion in the given array is" << cnt << endl;
    return 0;
}