// Maximum sum path in Binary Tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;    // Data stored in the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    int maxPathSum(TreeNode* root)
    {
        int maxSum=INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }
    public:
    int dfs(TreeNode* node,int &maxSum)
    {
        if(!node) return 0;
        int left=max(0,dfs(node->left,maxSum));
        int right=max(0,dfs(node->right,maxSum));
        maxSum=max(maxSum,left+right+node->data);
        return max(left,right)+node->data;
    }
};
int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;
    return 0;
}