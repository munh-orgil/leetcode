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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a = dfs(root);
        return build(a, 0, a.size() - 1);
    }
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {};
        }
        vector<int> ret = dfs(node->left);
        ret.push_back(node->val);
        vector<int> r = dfs(node->right);
        ret.insert(ret.end(), r.begin(), r.end());
        return ret;
    }
    TreeNode* build(const vector<int>& a, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int m = (l + r) / 2;
        TreeNode* ret = new(TreeNode);
        ret->val = a[m];
        ret->left = build(a, l, m - 1);
        ret->right = build(a, m + 1, r);
        return ret;
    }
};