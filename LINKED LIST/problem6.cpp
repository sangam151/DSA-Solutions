//Reverse a Linked List
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
Node *convertArr2LL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* reverseLL(Node* head)
{
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front; 
    }
    return prev;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    Node *newHead=reverseLL(head);
    cout<<newHead->data<<endl;
    return 0;
}