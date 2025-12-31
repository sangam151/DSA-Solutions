// Check if Tree is BST or BS
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root,INT_MIN,INT_MAX);
    }
    bool isValidBST(TreeNode* root,long minVal,long maxVal)
    {
        if(root==NULL) return true;
        if(root->val >=maxVal || root->val <=minVal) return false;
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
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
    bool ans = obj.isValidBST(root);
    if(ans)
    {
        cout<<"it is a Binary Search Tree"<<endl;
    }
    else{
        cout<<"it is noot a Binary search Tree"<<endl;
    }
}