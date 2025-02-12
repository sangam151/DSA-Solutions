//Find the Majority Element that occurs more than N/2 times by brute force approach
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> arr)
{
    int size=arr.size();
    for(int i=0;i<size;i++)
    {
        int cnt=0;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])cnt++;
        }
        if(cnt>(size/2))
        return arr[i];
    }
}

int main()
{
    vector<int> arr={2,2,1,1,1,2,2};
    int ans=majorityElement(arr);
    cout<<"the majority element that occurs more than N/2 is"<<ans<<endl;


    return 0;
}


