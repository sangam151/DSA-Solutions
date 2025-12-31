//LCA in Binary Search Tree
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
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode p, TreeNode q)
{
    if(root==NULL) return NULL;
    int curr=root->val;
    if(curr<p.val && curr<q.val)
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    if(curr>p.val && curr>q.val)
    {
        return lowestCommonAncestor(root->left,p,q);
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
    TreeNode* ans=obj.lowestCommonAncestor(root,2,7);
    cout<<"LCA of BST is: "<<ans->val<<endl;

}