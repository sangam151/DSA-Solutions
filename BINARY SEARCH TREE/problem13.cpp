// Kth largest and smallest element in binary search tree
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
public:
    void inorderTraversal(TreeNode *node, vector<int> &values)
    {
        if (node)
        {
            inorderTraversal(node->left, values);
            values.push_back(node->data);
            inorderTraversal(node->right, values);
        }
    }
    vector<int> kLargesSmall(TreeNode *root, int k)
    {
        vector<int> values;
        inorderTraversal(root, values);
        int kth_smallest = values[k - 1];
        int kth_largest = values[values.size() - k];
        return {kth_smallest, kth_largest};
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    Solution solution;
    int k = 1;
    vector<int> result = solution.kLargesSmall(root, k);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}