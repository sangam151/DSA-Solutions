#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor for last node (next = nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    // Constructor with next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};
Node *deleteKth(Node *head, int k)
{
    if(head==NULL) return head;
    if(k==1)
    {
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0; Node* temp=head;
    while(temp->next==nullptr)
    {
        cnt++;
        if(cnt==k-1)
        {
            Node * del=temp->next;
            temp=temp->next;
            free(del);
        }
      temp=temp->next;
}
return head;
}
int main()
{
    
    vector<int> arr = {2, 5, 8, 7};

    // Create last node first
    Node *head = new Node(arr.back());

    // Insert nodes in reverse order, linking to the previous
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        head = new Node(arr[i], head); // new head points to current head
    }
    int k = 2;
  head = deleteKth(head, k);
    while(head->next==nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;

    }
    cout<<head->data<<endl;

    return 0;
}
