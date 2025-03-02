// 4 sum by optimal approach
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Find4Sum(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++)
    {
        // avoid duplicate while moving through i
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid duplicate while moving through j
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int l=n-1;
            //2 pointer
            while(k<l)
            {
            int sum=arr[i]+arr[j]+arr[k]+arr[l];
            if(sum==target)
            {
                ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                k++;l--;
                while(k<l && arr[k]==arr[k-1])k++;
                while(k<l && arr[l]==arr[l+1])l--;
            }
            else if(sum<target)k++;
            else l--;
            

            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = Find4Sum(arr, target);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}