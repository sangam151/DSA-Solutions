// construct the BST using preorder Traversal
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
    TreeNode *bstFromPreorder(vector<int> &A)
    {
        int i = 0;
        return build(A, i, INT_MAX);
    }
    TreeNode *build(vector<int> &A, int &i, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};
int main()
{
    vector<int> A = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode *ans = sol.bstFromPreorder(A);

    return 0;
}