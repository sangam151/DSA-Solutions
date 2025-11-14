// starting point of the linked list
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
int startingPointOfLL(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, int> nodeMap;
    while (temp != nullptr)
    {
        if (nodeMap.find(temp) != nodeMap.end())
        {
            return temp->data;
        }
        nodeMap[temp] = 1;
        temp = temp->next;
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
    fifth->next = third;

    return head;
}
int main()
{
    Node *head = createLoopList();
    cout << startingPointOfLL(head) << endl;

    return 0;
}