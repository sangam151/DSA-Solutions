#include<bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int>&a,int num)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    int n=a.size();//size of array
    int longest=1;
    //pick a element ans search for its consecutive numbers 
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        int cnt=1;
        while(linearSearch(a,x+1)== true)
        {
            x+=1;
            cnt+=1;
        }
        longest=max(longest,cnt);
    }
    return longest;

}

int main(){
    vector<int> a={100,200,1,2,3,4};
    int ans=longestSuccessiveElements(a);
    cout<<"The longest consecutive sequence is "<<ans<<endl;
    return 0;
}