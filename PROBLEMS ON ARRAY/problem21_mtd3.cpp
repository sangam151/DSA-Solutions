// find next lexicographically greater permutation by optimal approach
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array
    // step 1:find the break point
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }
    // if break point does not exist
    if (ind == -1)
    {
        // reverse the whole array
        reverse(A.begin(), A.end());
        return A;
    }
    // step 2: The next greater element
    // and swap it with arr[ind]
    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }
    // reverse the right half
    reverse(A.begin() + ind + 1, A.end());
    return A;
}
int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);
    cout << "The next Permutation is : [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}
