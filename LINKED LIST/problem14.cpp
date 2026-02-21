// Remove the nth node from the end of the linked list
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
    void printLL(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    Node *deleteNthNodeFromEnd(Node *head, int N)
    {
        if (head == NULL)
            return NULL;
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        if (cnt == N)
        {
            Node *newHead = head->next;
            delete head;
            return newHead;
        }
        int res = cnt - N;
        temp = head;
        while (temp != NULL)
        {
            res--;
            if (res == 0)
                break;
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Creating linked list manually
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    Solution sol;
    head = sol.deleteNthNodeFromEnd(head, N);
    sol.printLL(head);
}