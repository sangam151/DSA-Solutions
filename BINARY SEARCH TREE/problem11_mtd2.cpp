// Two sum in BST || check if there exist a pair with sum k using optimal approach
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse) : reverse(isReverse)
    {
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
        {
            pushAll(tmpNode->right);
        }
        else
        {
            pushAll(tmpNode->left);
        }
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            myStack.push(node);
            if (reverse)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    cout << "Tree Initialized: ";
    printInorder(root);
    cout << endl;
    Solution solution;
    int target = 22;
    bool exists = solution.findTarget(root, target);
    if (exists)
        cout << "Pair with sum " << "exists." << endl;
    else
        cout << "Pair with sum" << target << " does not exist" << endl;
    return 0;
}