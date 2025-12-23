//ZigZag Traversal In Binary Tree
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int index=leftToRight?i:size-1-i;
                level[index]=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight=!leftToRight;
            result.push_back(level);
        }
        return result;
    }
};
int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans=sol.zigzagLevelOrder(root);
    cout<<"[";
    for(auto& level:ans)
    {
        cout<<"[";
        for(int i=0;i<level.size();i++)
        {
            cout<<level[i];
            if(i!=level.size()-1) cout<<", ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
    
    return 0;
}