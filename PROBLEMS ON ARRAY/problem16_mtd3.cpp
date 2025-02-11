//Sort an array of 0s, 1s and 2s by optimal approach (Dutch National flag algorithm.)
#include<bits/stdc++.h>
using namespace std;
vector<int> sortArray(vector<int> arr,int n)
{
    int left=0,mid=0,right=n-1;
    while(mid<=right)
    {
        if(arr[mid]==0)
        {
            swap(arr[left],arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;

        }
        else{
            swap(arr[mid],arr[right]);
            right--;    
            
        }
    }
    return arr;
}
int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    
    vector<int> ans=sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}