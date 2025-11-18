// Implement queue using stack
#include <bits/stdc++.h>
using namespace std;
class QueueUsingStack
{
    stack<int> s1, s2;
    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int top()
    {
        s1.top();
    }
    void pop()
    {
        s1.pop();
    }
};
class optimal
{
    stack<int> s1, s2;
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (s2.empty() != 1)
            s2.pop();
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                s2.push(s1.top());
                s2.pop();
            }
        }
    }
    int top()
    {
        if (s2.empty() != 1)
            return s2.top();
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                s2.push(s1.top());
                return s2.top();
            }
        }
    }
};
int main()
{
    return 0;
}
