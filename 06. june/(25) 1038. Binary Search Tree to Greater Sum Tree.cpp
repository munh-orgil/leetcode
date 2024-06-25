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
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* node) {
        TreeNode* ret = new(TreeNode);
        if (node->left == NULL && node->right == NULL) {
            sum += node->val;
            ret->val = sum;
            return ret;
        }
        if (node->right != NULL) {
            ret->right = dfs(node->right);
        }
        sum += node->val;
        ret->val = sum;
        if (node->left != NULL) {
            ret->left = dfs(node->left);
        }
        return ret;
    }
};