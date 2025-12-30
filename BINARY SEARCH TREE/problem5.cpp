// ceil In Binary Tree
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
    int ceilInBST(TreeNode *root, int key)
    {
        int ceil = -1;
        while (root)
        {
            if (root->val == key)
            {
                ceil = root->val;
                return ceil;
            }
            if (key > root->val)
            {

                root = root->right;
            }
            else
            {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
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
    int ceil = obj.ceilInBST(root, 5);
    if (ceil != -1)
    {
        cout << "ceil of key is: " << ceil << endl;
    }
    else
    {
        cout << "No ceil is found" << endl;
    }

    return 0;
}