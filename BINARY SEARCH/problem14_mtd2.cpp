//find the square root of the number by binary search
#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    int low=1,high=n;
    int ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        long long val=mid*mid;
        if(val<=(n*1ll))
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    int n=28;
    int ans=floorSqrt(n);
    cout<<"The floor of square root of "<<n<<" is "<<ans<<endl;
    return 0;
}