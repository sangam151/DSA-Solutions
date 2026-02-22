// Add 1 to a number by LL
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
    Node *reverseList(Node *node)
    {
        Node *prev = nullptr;
        Node *current = node;

        while (current)
        {
            Node *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        head = reverseList(head);
        Node *current = head;
        int carry = 1;
        while (current && carry)
        {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;
            if (!current->next && carry)
            {
                current->next = new Node(carry);
                carry = 0;
            }
            current = current->next;
        }
        head = reverseList(head);
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