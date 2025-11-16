// Flattening the linked list by brute force approach
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    // constructor to initialize the data next and child pointer
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};
Node* merge(Node* list1,Node* list2)
{
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data < list2->data)
        {
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=NULL;
    }
    //connect the remaining element if any
    if(list1)
    {
        res->child=list1;
    }
    else{
        res->child=list2;
    }
    /*
    if(dummyNode->child)
    {
        dummyNode->child->next=NULL;
    }*/
    return dummyNode->child;
}
// Function to flatten a Linked List with child Pointers
Node *flattenLinkedList(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //Recursively flatten the rest of the linked list
    Node* mergedHead=flattenLinkedList(head->next);
    head=merge(head,mergedHead);
    return head;
    
}
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}
void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->child)
        {
            cout << "->";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "|   ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(4);
    head->next->child = new Node(10);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
