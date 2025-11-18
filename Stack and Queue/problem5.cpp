//Implement stack using Queue
#include <bits/stdc++.h>
using namespace std;
class StackUsingQueue
{
public:
    int size = 0;
    queue<int> q;
    void push(int x)
    {
        size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
        size += 1;
    }
    void pop()
    {
        q.pop();
        size -= 1;
    }
    int top()
    {
        return q.front();
    }
    int size()
    {
        return size;
    }
};
int main()
{

    return 0;
}