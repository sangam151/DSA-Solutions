//4 sum by better approach
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> Find4Sum(vector<int> arr,int target)
{
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            set<int> set1;
            for(int k=j+1;k<n;k++)
            {
                int sum=arr[i]+arr[j]+arr[k];
                int fourth=target-sum;
                if(set1.find(fourth)!=set1.end())
                {
                    vector<int> temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                //put the kth element
                set1.insert(arr[k]);
            }
        }

    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
   
}

int main()
{
    vector<int> arr={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=Find4Sum(arr,target);
    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    return 0;

}