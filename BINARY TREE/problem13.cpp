// Boundary Traversal In Binary Tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;        // Data stored in the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }
    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        vector<int> temp;
        TreeNode *curr = root->right;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            res.push_back(temp[i]);
    }
    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        // if root is not a leaf push it to res
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
    void printResult(vector<int> res)
    {
        cout << endl;
        for (int i = 0; i < res.size(); i++)
        {

            cout << res[i] << ",";
        }
        cout << endl;
    }
};
int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    vector<int> result = solution.printBoundary(root);
    solution.printResult(result);
    return 0;
}