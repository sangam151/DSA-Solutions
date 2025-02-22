//find the triplets that sum up to zero by optimal approach
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr)
{
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
  
        for(int i=0;i<n-2;i++)
        {
            if(i!=0 && arr[i]==arr[i-1])continue;
            int j=i+1; int k=n-1;
            while(j<k){
            int sum=arr[i]+arr[j]+arr[k];  
            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;

            }
        } 
        }
    
    return ans;
}

int main(){
    vector<int> arr={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=findTriplets(arr);
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