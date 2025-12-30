// Floor In Binary Tree
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
        int floor = -1;
        while (root)
        {
            if (root->val == key)
            {
                floor = root->val;
                return floor;
            }
            if (key > root->val)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
            return floor;
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
    int ceil = obj.ceilInBST(root, 5);
    if (ceil != -1)
    {
        cout << "Ceil of key is: " << ceil << endl;
    }
    else
    {
        cout << "No floor is found" << endl;
    }

    return 0;
}