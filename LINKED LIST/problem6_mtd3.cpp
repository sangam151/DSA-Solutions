// Reverse a Linked List by brute force approach
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
Node *reverseLL(Node *head)
{
   Node* temp=head;
   stack<int> st;
   while(temp!=nullptr)
   {
    st.push(temp->data);
    temp=temp->next;
   }
   temp=head;
   while(temp!=nullptr)
   {
    temp->data=st.top();
    st.pop();
    temp=temp->next;
   }
   return head;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    Node *newHead = reverseLL(head);
    cout << newHead->data << endl;
    return 0;
}