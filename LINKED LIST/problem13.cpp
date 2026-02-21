// Segregate even and odd nodes in linkedlist
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode(int x)
    {
        value = x;
        next = nullptr;
    }
};
ListNode *head, *tail;
void PrintList(ListNode *head)
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
    {
        cout << curr->value << "-->";
    }
    cout << "null" << endl;
}
void InsertatLast(int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == nullptr)
    {
        head = newNode, tail = newNode;
    }
    else
    {
        tail = tail->next = newNode;
    }
}
ListNode *SegregatetoOddEven()
{
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;
        if (temp->value & 1)
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next;
    return evenHead->next;
}
int main()
{
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    cout << "Initial LinkedList: " << endl;
    PrintList(head);
    ListNode *newHead = SegregatetoOddEven();
    cout << "LinkedList After Segregation " << endl;
    PrintList(newHead);
    return 0;
}