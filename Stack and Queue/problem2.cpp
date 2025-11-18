//Implement queue using array

#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int size;
    int arr[10];
    int currentSize;
    int start;
    int end;

public:
    Queue()
    {
        size=10;
        currentSize=0;
        start=-1;
        end=-1;
    }
    void push(int x)
    {
        if(currentSize==size) cout<<"exceeded"<<endl;
        if(currentSize==0)
        {
            start=0,end=0;
        }
        else{
            end=(end+1)%size;
        }
        arr[end]=x,currentSize+=1;
    }
    void pop()
    {
        if(currentSize==0) cout<<"No element in the stack"<<endl;
        int el=arr[start];
        if(currentSize==1)
        {
            start=end=-1;
        }
        else{
            start=(start+1)%size;
        }
        currentSize-=1;  
    }
    int Top()
    {
        if(currentSize==0) cout<<"No element in the stack"<<endl;
        return arr[start];
    }
    int Size()
    {
        return currentSize;
    }
};
int main()
{
    return 0;
}