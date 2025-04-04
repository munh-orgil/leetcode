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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> anc;
        function<void(TreeNode*, int)> rec;
        rec = [&](TreeNode* node, int p) {
            if (node == NULL) return;
            if (node->val > anc.size()) {
                anc.resize(node->val + 1);
            }
            anc[node->val] = anc[p];
            anc[node->val].push_back(node);
            rec(node->left, node->val);
            rec(node->right, node->val);
            };

        rec(root, 0);
        int n = anc.size(), mx = 0;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (anc[i].size() > mx) {
                idx = { i };
                mx = anc[i].size();
            } else if (anc[i].size() == mx) {
                idx.push_back(i);
            }
        }
        bool ok;
        TreeNode* ret;
        for (int i = 0; i < mx; i++) {
            ok = 1;
            for (int j = 0; j < idx.size(); j++) {
                if (anc[idx[j]][i] != anc[idx[0]][i]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                break;
            }
            ret = anc[idx[0]][i];
        }
        return ret;
    }
};