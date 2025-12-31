// Insert the given Node in Binary Search Tree
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if(root==NULL) return new TreeNode(val);
        TreeNode* cur=root;
        while (true)
        {
            if(cur->val<=val)
            {
                if(cur->right !=NULL)cur=cur->right;
                else
                {
                    cur->right=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(cur->left !=NULL) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }

        }
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
    TreeNode *ans = obj.insertIntoBST(root, 5);
}