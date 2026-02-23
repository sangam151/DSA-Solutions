// Clone Linked list with random and next pointer
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
};
void printClonedLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->data;
        if (head->random != nullptr)
        {
            cout << ", Random: " << head->random->data;
        }
        else
        {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}
Node *cloneLL(Node *head)
{
    if (!head)
        return nullptr;
    unordered_map<Node *, Node *> mp;
    Node *temp = head;
    while (temp != nullptr)
    {
        mp[temp] = new Node(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);
    Node *clonedList = cloneLL(head);
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);
    return 0;
}