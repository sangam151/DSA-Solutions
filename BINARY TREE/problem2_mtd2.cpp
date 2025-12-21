// Inorder Transversal of Binary Tree using Iterative Approach
#include <bits/stdc++.h>
using namespace std;
// Define the TreeNode structure
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    // Function to perform tranversal of a binary tree iteratively
    vector<int> inorder(TreeNode *root)
    {
        // Initialize a stack to track Nodes
        stack<TreeNode *> st;
        // start from the root Node
        TreeNode *node = root;
        // Initialize a vector to store inorder transversal result
        vector<int> inorder;
        // start a infinite Loop for Transversal
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                // Move to left child of the current Node
                node = node->left;
            }
            else
            {
                // if stack is emwpty break from loop
                if (st.empty())
                {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    vector<int> result = sol.inorder(root);
    cout << "Inorder Transversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}