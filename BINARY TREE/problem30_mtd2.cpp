// flatten binary tree to linked list by better approach
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (cur->right != nullptr)
                st.push(cur->right);
            if (cur->left != nullptr)
                st.push(cur->left);
            if (!st.empty())
                cur->right = st.top();
            cur->left = nullptr;
        }
    }
};
void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printFlattenTree(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    Solution sol;
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    sol.flatten(root);
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}