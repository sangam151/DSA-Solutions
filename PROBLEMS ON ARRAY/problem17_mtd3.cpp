//Find the Majority Element that occurs more than N/2 times by optimal approach(Moore's voting algorithm)
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> arr)
{
    //size of the given array
    int n=arr.size();
    int cnt=0;//count
    int el;//element
    //applying the algorithm
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt=1;
            el=arr[i];
        }
        else if(el=arr[i])cnt++;
        else cnt--;
    }
    //checking if the stored element is the majority element
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(el==arr[i])cnt1++;

    }
    if(cnt1>(n/2))
    return el;
    return -1;

}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int ans=majorityElement(arr);
    cout<<"the majority element occurs more than N/2 is "<<ans<<endl;

    return 0;
}