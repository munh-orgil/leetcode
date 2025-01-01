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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> notRoot;
        for (auto d : descriptions) {
            if (mp.find(d[0]) == mp.end()) {
                mp[d[0]] = new(TreeNode);
                mp[d[0]]->val = d[0];
            }
            if (mp.find(d[1]) == mp.end()) {
                mp[d[1]] = new(TreeNode);
                mp[d[1]]->val = d[1];
            }
            if (notRoot.find(d[0]) == notRoot.end()) {
                notRoot[d[0]] = 0;
            }
            notRoot[d[1]] = 1;
            if (d[2]) {
                mp[d[0]]->left = mp[d[1]];
            }
            else {
                mp[d[0]]->right = mp[d[1]];
            }
        }
        for (auto [k, v] : notRoot) {
            if (!v) {
                return mp[k];
            }
        }
        return nullptr;
    }
};
