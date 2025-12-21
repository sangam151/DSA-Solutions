// PreOrder Transversal in Binary Tree
#include <bits/stdc++.h>
using namespace std;
// Node Structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // constructor to initialize the node with value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Solution class containing transversal function
class Solution
{
public:
    void preorder(Node *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        arr.push_back(root->data);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    vector<int> preOrder(Node *root)
    {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Solution sol;
    vector<int> result = sol.preOrder(root);
    cout << "Preorder Traversal" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}