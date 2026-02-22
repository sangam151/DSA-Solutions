// Add 1 to a number by LL by recursive approach
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *append(Node *head, int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            return newNode;
        }
        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }
    void printList(Node *head)
    {
        Node *current = head;
        while (current)
        {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};
class Solution
{
public:
    int addOneUtil(Node *node)
    {
        if (!node)
            return 1;
        int carry = addOneUtil(node->next);
        int sum = node->data + carry;
        node->data = sum % 10;
        return sum / 10;
    }
    Node *addOne(Node *head)
    {
        int carry = addOneUtil(head);
        if (carry)
        {
            Node *newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};
int main()
{
    Node *head = nullptr;
    LinkedList ll;
    Solution sol;
    head = ll.append(head, 1);
    head = ll.append(head, 2);
    head = ll.append(head, 9);
    cout << "Original Number: ";
    ll.printList(head);
    head = sol.addOne(head);
    cout << "After Adding One: ";
    ll.printList(head);
    return 0;
}