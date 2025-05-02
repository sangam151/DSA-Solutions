// find the repeating and missing numbers by better approach
#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();//size of the array
    int hash[n + 1] = {0};//hash array
    int repeating=-1,missing=-1;
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for(int i=0;i<n+1;i++)
    {
        if(hash[i]==2) repeating=i;
        else if(hash[i]==0)missing=i;
    }
    return {repeating,missing};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeatating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
