// Nth root of the number by using linear search
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
int NthRoot(int n, int m)
{
    // use linear search on the answer space
    for (int i = 1; i <= m; i++)
    {
        long long val = func(i, n);
        if (val == m * 1ll)
            return i;
        else if (val > m * 1ll)
        {
            break;
        }
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << endl;
    return 0;
}