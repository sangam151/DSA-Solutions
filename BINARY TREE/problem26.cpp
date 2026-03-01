// Construct the binary tree using Inorder and Postorder
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
    TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode *build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsRight = inEnd - inRoot;
        root->left = build(postorder, postStart, postEnd - numsRight - 1, inorder, inStart, inRoot - 1, inMap);
        root->right = build(postorder, postEnd - numsRight, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};
void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main()
{
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    Solution sol;
    TreeNode *root = sol.buildTree(postorder, inorder);
    cout << "Inorder of Unique Binary tree create:\n";
    printInorder(root);
    cout << endl;
    return 0;
}