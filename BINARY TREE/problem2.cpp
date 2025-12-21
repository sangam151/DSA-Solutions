//Inorder Tranversal In Binary Tree
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
    void inorder(Node *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    vector<int> inOrder(Node *root)
    {
        vector<int> arr;
        inorder(root, arr);
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
    vector<int> result = sol.inOrder(root);
    cout << "inorder Traversal" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}