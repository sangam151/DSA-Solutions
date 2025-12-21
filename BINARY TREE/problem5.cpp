// PreOrder Transversal in Binary Tree using iterative approach
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
    vector<int> preorderTraversal(Node *root)
    {
        vector<int> preorder;
        if (root == nullptr)
        {
            return preorder;
        }
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->data);
            if (root->right != nullptr)
            {
                st.push(root->right);
            }
            if (root->left != nullptr)
            {
                st.push(root->left);
            }
        }
        return preorder;
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
    vector<int> result = sol.preorderTraversal(root);
    cout << "Preorder Traversal" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}