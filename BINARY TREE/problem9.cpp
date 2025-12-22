#include<bits/stdc++.h>
using namespace std;
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
    int diameter=0;
    int calculateHeight(Node* node)
    {
        if(node==nullptr) return 0;
        int leftHeight=calculateHeight(node->left);
        int rightHeight=calculateHeight(node->right);
        diameter=max(diameter,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);


    }
    int diameterOfBinaryTree(Node* root)
    {
        calculateHeight(root);
        return diameter;
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
    int diameter=solution.diameterOfBinaryTree(root);
    cout<<"The diameter of the binary tree is "<<1+diameter<<endl;
    return 0;
}