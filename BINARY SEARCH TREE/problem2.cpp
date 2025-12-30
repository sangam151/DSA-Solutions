// Max/Min In Binary Tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};
class Solution
{
public:
    TreeNode *maxInBST(TreeNode *root)
    {
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }
    
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution obj;
    TreeNode *resultMax = obj.maxInBST(root);
    
    cout<<"Max in BST is: "<<resultMax->val<<endl;

    return 0;
}