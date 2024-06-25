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
    int sum = 0;
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }
};