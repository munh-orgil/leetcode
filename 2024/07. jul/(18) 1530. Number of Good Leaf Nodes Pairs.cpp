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
    unordered_map<TreeNode*, TreeNode*> par;
    int countPairs(TreeNode* root, int distance) {
        par = unordered_map<TreeNode*, TreeNode*>();
        setParent(root);
        vector<TreeNode*> leaves = findLeaves(root);
        int ret = 0;
        for (auto leaf : leaves) {
            ret += bfs(leaf, distance);
        }
        ret /= 2;
        return ret;
    }
    void setParent(TreeNode* node) {
        if (node->left != NULL) {
            setParent(node->left);
            par[node->left] = node;
        }
        if (node->right != NULL) {
            setParent(node->right);
            par[node->right] = node;
        }
    }
    vector<TreeNode*> findLeaves(TreeNode* node) {
        if (node == NULL) {
            return {};
        }
        if (checkLeaf(node)) {
            return { node };
        }
        vector<TreeNode*> l = findLeaves(node->left);
        vector<TreeNode*> r = findLeaves(node->right);
        vector<TreeNode*> ret = l;
        for (auto n : r) {
            ret.push_back(n);
        }
        return ret;
    }
    bool checkLeaf(TreeNode* node) {
        if (node == NULL) {
            return false;
        }
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }
    int bfs(TreeNode* root, int maxDist) {
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, bool> vis;
        q.push({ root, 0 });
        vis[root] = 1;
        int ret = 0;
        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            vis[node] = 1;
            if (node != root && checkLeaf(node)) {
                ret++;
            }
            d++;
            if (d <= maxDist) {
                if (par[node] != NULL && !vis[par[node]]) {
                    q.push({ par[node], d });
                }
                if (node->left != NULL && !vis[node->left]) {
                    q.push({ node->left, d });
                }
                if (node->right != NULL && !vis[node->right]) {
                    q.push({ node->right, d });
                }
            }
        }
        return ret;
    }
};
