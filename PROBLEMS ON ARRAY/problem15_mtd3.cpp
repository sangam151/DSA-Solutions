//Check if a pair with given sum exists in Array by optimal approach (using two pointer approach)
#include<bits/stdc++.h>
using namespace std;
string twoSum(vector<int> arr,int n,int target)
{
    sort(arr.begin(),arr.end());
    int left=0,right=n-1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }


  
  return "NO";
}
int main(){
    int n=5;
    vector<int> arr={2,6,5,8,11};
    int target=14;
    string ans=twoSum(arr,n,target);
    cout<<"this is the answer for varient 1 "<<ans<<endl;
    return 0;
}