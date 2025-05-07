//find next lexicographically greater permutation by brute force approach
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums,int start)
    {
        if(start==nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[start],nums[i]);
            backtrack(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>>permute(vector<int>&nums)
    {
        backtrack(nums,0);
        nextPermutation(result,nums);

    }
    void nextPermutation(vector<vector<int>> result,vector<int> nums)
    {
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++)
        {
            if(result[i]==nums)
            {
                int nextindex=(i+1)%result.size();
                cout<<"next permutation"<<endl;
                for(int it:result[nextindex])
                {   
                    cout<<it<<" ";
                }
            }
        }
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    sol.permute(nums);
    return 0;
}