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
    int floorInBST(TreeNode *root, int key)
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
        }
        return floor;
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
    int floor = obj.floorInBST(root, 5);
    if (floor != -1)
    {
        cout << "Floor of key is: " << floor << endl;
    }
    else
    {
        cout << "No floor is found" << endl;
    }

    return 0;
}