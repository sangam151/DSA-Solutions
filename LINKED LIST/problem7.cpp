//Detect the cycle in Linked List by brute force approch
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
bool detectLoop(Node * head)
{
    Node* temp=head;
    unordered_map<Node*,int> nodeMap;
    while(temp!=nullptr)
    {
        if(nodeMap.find(temp)!=nodeMap.end())
        {
            return true;
        }
        nodeMap[temp]=1;
        temp=temp->next;
    }
    return false;
}
Node* createLoopList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next=third;

    return head;
}
int main()
{
    Node* head=createLoopList();
    if(detectLoop(head)) cout<<"true"<<endl;
    else  cout<<"false"<<endl;

    return 0;
}