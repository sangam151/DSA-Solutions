#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> a )
{
    long long n=a.size();
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^a[i];
        xr=xr^(i+1);
    }
    int bitno=0;
    while(1)
    {
        if((xr &(1<<bitno))!=0)
        {
            break;
        }
        bitno++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
            //part of 1 club
            if((a[i]&(1<<bitno))!=0)
            {
                one=one^a[i];
            }
            //part of zero club
            else 
            {
                zero=zero^a[i];
            }
    }
    for(int i=1;i<=n;i++)
    {
        //part of 1 club
        if(i&(1<<bitno)!=0)
        {
            one=one^i;
        }
            //part of o club
            else{
                zero=zero^i;
            }
        
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==zero)cnt++;
    }
    if(cnt==2)return{zero,one};
    return{one,zero};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeatating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";
    
    return 0;

}

