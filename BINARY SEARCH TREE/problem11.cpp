// Two sum in BST | check if there exist a pair with sum K
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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int left = 0;
        int right = inorder.size() - 1;
        while (left < right)
        {
            int sum = inorder[left] + inorder[right];
            if (sum == k)
                return true;
            else if (sum < k)
                left++;
            else if (sum > k)
                right--;
        }
        return false;
    }

private:
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

};
void printInorder(TreeNode* root)
{
    if(!root) return;
    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    // print inorder traversal
    cout << "Tree initialized" << endl;
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