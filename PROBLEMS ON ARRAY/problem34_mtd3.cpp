// find the repeating and missing number by optimal approach 1
#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();//size of the array
    //find the sn and s2n
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    //find s and s2
    for (int i = 0; i < n; i++)
    {
        s = s + (long long)a[i];
        s2 = s2 + ((long long)a[i] * (long long)a[i]);
    }
    //s-sn=x-y
    long long val1=s-sn;
    //s2-s2n=x^2-y^2
    long long val2=s2-s2n;
    //find x+y=(x^2-y^2)/(x-y)
    val2=val2/val1;
    //find x and y: x=((x-y)+(x+y))/2 and y=x-val1
    //val1=x-y val2=x+y
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return {(int)x,(int)y};



}
int main()
{

 
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeatating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}