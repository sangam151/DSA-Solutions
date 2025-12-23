// Check if two Trees are Identical or not
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    bool isIdentical(Node* root1,Node* root2)
    {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        return ((root1->data==root2->data) && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
    }
};
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(4);
    root1->right = new Node(3);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(4);
    root2->right = new Node(3);
    Solution sol;
    if (sol.isIdentical(root1, root2))
    {
        cout << "The Binary Tree is Identical" << endl;
    }
    else
    {
        cout << "The Binary Tree is Not Identical" << endl;
    }
    return 0;
}