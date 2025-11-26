// Implement Min Stack
#include <bits/stdc++.h>
using namespace std;
int mini = INT_MAX;
class MinStack
{
public:
    stack<int> st;
    int x;
    

    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val > mini)
                st.push(val);
            else
            {
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }
    void pop()
    {
        if (st.empty())
            return;
        x = st.top();
        st.pop();
        if (x < mini)
        {
            mini = 2 * mini - x;
        }
    }
    int top()
    {
        if (st.empty())
            return -1;
        x = st.top();
        if (mini < x)
            return x;
        else
            return mini;
    }
};
int main()
{
    MinStack m1;
    m1.push(10);
    m1.push(11);
    m1.push(12);
    m1.push(9);
    m1.pop();
    cout<<m1.top()<<"\n"<<mini;
    return 0;
}