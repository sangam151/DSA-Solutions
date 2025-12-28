// Check for Childerem sum property in Binary Tree
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
    void changeTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        int child = 0;
        if (root->left)
        {
            child += root->left->val;
        }
        if (root->right)
        {
            child += root->right->val;
        }
        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            if (root->left)
            {
                root->left->val = root->val;
            }
            else if (root->right)
            {
                root->right->val = root->val;
            }
        }
        changeTree(root->left);
        changeTree(root->right);
        int tot = 0;
        if (root->left)
        {
            tot += root->left->val;
        }
        if (root->right)
        {
            tot += root->right->val;
        }
        if (root->left || root->right)
        {
            root->val = tot;
        }
    }
};
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);
    cout << "Binary Tree Before Modification: ";
    inorderTraversal(root);
    cout << endl;
    Solution sol;
    sol.changeTree(root);
    cout << "Binary Tree after Childen Sum Property: ";
    inorderTraversal(root);
    return 0;
}