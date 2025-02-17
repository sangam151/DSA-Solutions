//longest consecutive sequence in the array by optimal approach
#include<bits/stdc++.h>
using namespace std;
int longestSuccessiveElement(vector<int> a)
{
    int n=a.size();
    if(n==0)return 0;
    int longest=1;
    unordered_set<int> st;
    //put all the array element into the set
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            //find consecutive number
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x=x+1;
                cnt+=1;

            }
            longest=max(longest,cnt);
        }

    }
    return longest;
}
int main(){
    vector<int> a ={100,200,1,2,3,4};
    int ans=longestSuccessiveElement(a);
    cout<<"The longest consecutive sequence in the array is "<<ans;
    return 0;
}