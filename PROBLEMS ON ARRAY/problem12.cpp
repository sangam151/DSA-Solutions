//Count Maximum Consecutive One's in the array
#include<bits/stdc++.h>
using namespace std;
class solution
{
       public:
       int findMaxConsecutiveOnes(vector<int> arr)
       {
        int cnt=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1)
            cnt++;
            else
            cnt=0;
            maxi=max(maxi,cnt);
        }
        return maxi;
       } 
};
int main(){
    vector<int> arr={1,1,0,1,1,1};
    solution obj;
    int ans=obj.findMaxConsecutiveOnes(arr);
    cout<<"maximum 1's consecutive in the array is "<<ans<<endl;
    return 0;
}