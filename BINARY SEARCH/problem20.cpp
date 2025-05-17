/*Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’
 book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is 
minimum. If the allocation of books is not possible. return -1(brute force approach)*/
#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> arr, int mPages, int m)
{
    int n = arr.size();
    int sum = 0;
    int cnt=1;
    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
        if(sum>mPages)
        {
            cnt++;
            sum=arr[i];
        }
    }
    return cnt==m;
}
int minimumPages(vector<int> arr, int m)
{
    int n = arr.size(); // number of books
    int maxi = INT_MIN;
    int sum = 0;
    if (m > n)
        return -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum = sum + arr[i];
    }
    for (int i = maxi; i <= sum; i++)
    {
        if (possible(arr, i, m))
            return i;
    }
    return maxi;
}
int main()
{
    vector<int> arr = {25, 46, 28, 49,24};
    int m = 5; // number of student
    int ans = minimumPages(arr, m);
    cout << "Maximum number of pages assigned to a student is minimum is: " << ans << endl;
    return 0;
}   