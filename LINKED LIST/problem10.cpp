//Reverse Linked List in groups of size K 
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
Node* getKthNode(Node* head,int k)
{
    Node* temp=head;
    k--;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;

    }
    return temp;

}
Node* reverseLinkedList(Node* head)
{
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* kReverse(Node* head,int k)
{
    Node* temp=head;
    Node* prevLast=NULL;
    while(temp!=NULL)
    {
        Node* kThNode=getKthNode(temp,k);
        if(kThNode==NULL)
        {
            if(prevLast)
            {
                prevLast->next=temp;
            }
            break;
        }
        Node* nextNode=kThNode->next;
        kThNode->next=NULL;
        reverseLinkedList(temp);
        if(temp==head)
        {
            head=kThNode;
        }
        else{
            prevLast->next=kThNode;
        }
        prevLast=temp;
        temp=nextNode;
    }
    return head;
    

}
int main()
{
    vector<int> arr = {2, 5, 8, 7,5,4,7,9};
    Node *head = convertArr2LL(arr);
    Node* temp=kReverse(head,3);
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}