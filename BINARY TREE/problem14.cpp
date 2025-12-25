// Vertical Order Traversal in Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> findVertical(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            Node *temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(temp->data);

            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});

            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});
        }
        for (auto &p : nodes)
        {
            vector<int> col;
            for (auto &q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

void printResult(const vector<vector<int>> &result)
{
    for (auto &col : result)
    {
        for (int val : col)
            cout << val << " ";
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);
    Solution solution;
    vector<vector<int>> verticalTraversal = solution.findVertical(root);
    cout << "Vertical Traversal:\n";
    printResult(verticalTraversal);
    return 0;
}
