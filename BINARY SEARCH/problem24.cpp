/*Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the
 two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In
 case the length of the list is even, the median is the average of the two middle elements.*/
#include <bits/stdc++.h>
using namespace std;
double median(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> arr3;
    // apply the merge step
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if(a[i]<b[j]) arr3.push_back(a[i++]);
        else
        arr3.push_back(b[j++]);
    }
    while(i<n1)
    {
        arr3.push_back(a[i++]);
    }
    while(j<n2) arr3.push_back(b[j++]);
    //find the median
    int n=n1+n2;
    if(n%2==1)  return (double)arr3[n/2];
    double median=((double)arr3[n/2]+(double)arr3[(n/2)-1])/2.0;
    return median;
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is: " << fixed << setprecision(1) << median(a, b) << endl;
    return 0;
}