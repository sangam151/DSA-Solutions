//Implement stack using Linked List and queue using Linked List
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class StackLL
{
    public:
    Node* top=NULL;
    static int size;
    StackLL()
    {
        size=0;
    }
    void push(int x)
    {
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        size+=1;
    }
    void pop()
    {
        Node* temp=top;
        top=top->next;
        delete temp;
        size-=1;
    }
    int top()
    {
        return top->data;
    }
    int size()
    {
        return size;
    }


};
class QueueLL
{
    
    Node* start=NULL;
    Node* end=NULL;
    int size;
    public:
    QueueLL()
    {
        size=0;
    }
    void push(int x)
    {
        Node* temp=new Node(x);
        if(start==NULL)
        {
            start=end=temp;

        }
        else{
            end->next=temp;
            size+=1;
        }
    }
    void pop()
    {
        if(start==NULL) cout<<"No Element in the Queue"<<endl;
        Node* temp=start;
        start=start->next;
        delete temp;
        size-=1;
    }
    int top()
    {
        if(start==NULL) cout<<"No Element In the Queue"<<endl;
        return start->data;
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