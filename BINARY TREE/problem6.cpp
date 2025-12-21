// Post order Traversal of Binary Tree using 2 stack
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
        {
            return postorder;
        }
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != NULL)
            {
                st1.push(root->left);
            }
            if (root->right != NULL)
            {
                st1.push(root->right);
            }
        }
        while (!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Object of solution
    Solution sol;

    // Call postorder traversal

    vector<int> result = sol.postorderTraversal(root);
    // Print result
    for (int val : result)
        cout << val << " ";
    return 0;
}