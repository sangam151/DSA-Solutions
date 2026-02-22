// remove duplicate from sorted linked list
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor to initialize node with given value
    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *head = nullptr;
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        // If list is empty, set new node as head
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }

        // Link the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }
    Node *removeDuplicates()
    {
        if (!head)
            return nullptr;
        Node *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            Node *nextDistinct = current->next;
            while (nextDistinct != nullptr && nextDistinct->data == current->data)
            {
                Node *duplicateNode = nextDistinct;
                nextDistinct = nextDistinct->next;
                delete duplicateNode;
            }
            current->next = nextDistinct;
            if (nextDistinct != nullptr)
            {
                nextDistinct->prev = current;
            }
            current = current->next;
        }
        return head;
    }
    void printList()
    {
        Node *current = head;

        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    // Initial list values (with duplicates)
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    for (int value : values)
    {
        sol.insertAtEnd(value);
    }
    cout << "Original List: ";
    sol.printList();
    sol.removeDuplicates();
    cout << "After Removing Duplicates (keeping 1 occurrence): ";
    sol.printList();
    return 0;
}