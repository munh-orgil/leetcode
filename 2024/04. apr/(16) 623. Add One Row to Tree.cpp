#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        dfs(root, 1, depth - 1, val);
        return root;
    }
    void dfs(TreeNode* node, int cur, int goal, int val) {
        if (node == NULL) {
            return;
        }
        if (cur == goal) {
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            node->left = new TreeNode(val, l, NULL);
            node->right = new TreeNode(val, NULL, r);
            return;
        }
        dfs(node->left, cur + 1, goal, val);
        dfs(node->right, cur + 1, goal, val);
    }
};