//length of loop in linked list by optimal approach 
#include <bits/stdc++.h>
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
int countLoopLength(Node* meetingPoint)
{
    Node* temp=meetingPoint;
    int length=1;
    while(temp->next !=meetingPoint)
    {
        temp=temp->next;
        length++;
    }
    return length;
}
int lengthOfLL(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    int timer=0;
    while(fast!=NULL && fast->next!=NULL)
    {
        
        slow=slow->next;
        
        fast=fast->next->next;
        if(slow==fast)
        {
           return countLoopLength(slow);
        }
        
    }
    return -1;
}
Node *createLoopList()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;

    return head;
}
int main()
{
    Node *head = createLoopList();
    cout << lengthOfLL(head) << endl;

    return 0;
}