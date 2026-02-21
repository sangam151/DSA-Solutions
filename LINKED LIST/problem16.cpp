// Sort a Linked list by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *sortLL(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        for (int i = 0; i < arr.size(); i++)
        {
            temp->data = arr[i];
            temp = temp->next;
        }
        return head;
    }
};
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);
    cout << "Orginal Linked List: ";
    printLinkedList(head);
    Solution obj;
    head = obj.sortLL(head);
    cout << "Sorted linked list: ";
    printLinkedList(head);
    return 0;
}