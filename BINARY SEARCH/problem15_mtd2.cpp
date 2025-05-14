//Nth root of the number by binary search
#include <bits/stdc++.h>
using namespace std;
int func(int b, int exp)
{
    long long ans = 1;
    long long base = b;
    while (exp > 0)
    {
        if (exp % 2)
        {
            exp--;
            ans = ans * base;
        }
        else
        {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}
int NthRoot(int n,int m)
{
    int low=1;
    int high=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        long long val=func(mid,n);
        if(val==(m*1ll))
        {
            return mid;
        }
        else if(val>mid)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}
int main()
{
    int n=3,m=27;
    int ans=NthRoot(n,m);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}