// correct BST with two node swapped
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != NULL && (root->data < prev->data))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
};
void printInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data;
    printInorder(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    Solution obj;
    obj.recoverTree(root);
    printInorder(root);
    return 0;
}