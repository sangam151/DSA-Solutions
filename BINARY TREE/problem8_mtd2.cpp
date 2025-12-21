//check if Binary tree is balanced or not by optimal approach
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;       // Data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    bool isBalanced(Node* root)
    {
        return dfsHeight(root)!=-1;
    }
    int dfsHeight(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftHeight=dfsHeight(root->left);
        if(leftHeight==-1)
        return -1;
        int rightHeight=dfsHeight(root->right);
        if(rightHeight==-1)
        return -1;
        if(abs(leftHeight-rightHeight)>1)
        return -1;
        return max(leftHeight,rightHeight)+1;
    }
};
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}