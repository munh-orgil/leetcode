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
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* ret = new(TreeNode);
        queue<TreeNode*> q;
        vector<int> lvl;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            lvl.push_back(sum);
        }
        lvl.push_back(0);
        return dfs(root, 0, lvl);
    }
    TreeNode* dfs(TreeNode* node, int cur, vector<int>& lvl) {
        TreeNode* ret = new(TreeNode);
        int val = lvl[cur + 1];
        if (node->left != NULL) {
            val -= node->left->val;
        }
        if (node->right != NULL) {
            val -= node->right->val;
        }
        if (node->left != NULL) {
            ret->left = dfs(node->left, cur + 1, lvl);
            ret->left->val = val;
        }
        if (node->right != NULL) {
            ret->right = dfs(node->right, cur + 1, lvl);
            ret->right->val = val;
        }
        return ret;
    }
};