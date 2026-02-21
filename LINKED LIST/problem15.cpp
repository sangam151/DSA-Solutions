// Delete the middle node of the linked list
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
    Node *deleteMiddle(Node *head)
    {
        Node *temp = head;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        int res = n / 2;
        temp = head;
        while (temp != NULL)
        {
            res--;
            if (res == 0)
            {
                Node *middle = temp->next;
                temp->next = temp->next->next;
                free(middle);
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
void printLL(Node *head)
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original Linked List: ";
    printLL(head);
    Solution obj;
    head = obj.deleteMiddle(head);
    cout << "Updated Linked List: ";
    printLL(head);
    return 0;
}