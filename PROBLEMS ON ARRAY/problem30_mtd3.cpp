//Element that appears more than N/3 times in the array by optimal approach
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> arr)
{
    int n=arr.size();
    int cnt1=0,cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    //applying extended boyer moore voting algorithm
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && arr[i]!=el2)
        {
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1)
        {
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1)cnt1++;
        else if(arr[i]==el2)cnt2++;
        else{
            cnt1--,cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el1)cnt1++;
        if(arr[i]==el2)cnt2++;
    }
    int mini=(n/3)+1;
    if(cnt1>=mini) ls.push_back(el1);
    if(cnt2>=mini)ls.push_back(el2);
    return ls;
}

int main(){
    vector<int> arr={11,33,33,11,33,11};
    vector<int> ans=majorityElement(arr);
    cout<<"The majority element are: ";
    for(auto it:ans)
    {
        cout<<it<<" ";

    }

    return 0;
}