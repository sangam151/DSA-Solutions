// Rotate a Linked List to the right by k position using optimal approach
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *tail = head;
        int cnt = 1;
        while (tail->next)
        {
            tail = tail->next;
            cnt++;
        }
        tail->next = head;
        k = k % cnt;
        int rotateKRight = cnt - k;
        ListNode *newTail = head;
        for (int i = 1; i < rotateKRight; i++)
        {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution obj;
    int k = 2;
    ListNode *result = obj.rotateRight(head, k);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}