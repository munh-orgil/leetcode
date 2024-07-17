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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        unordered_map<int, bool> del;
        for (int d : to_delete) {
            del[d] = 1;
        }
        function<void(TreeNode*, TreeNode*)> dfs{ [&](TreeNode* prev, TreeNode* cur) {
            if (cur == NULL) {
                return;
            }
            cout << cur->val << endl;
            if (del[cur->val]) {
                if (prev->left != nullptr && prev->left->val == cur->val) {
                    prev->left = nullptr;
                }
                if (prev->right != nullptr && prev->right->val == cur->val) {
                    prev->right = nullptr;
                }
                if (cur->left != nullptr && !del[cur->left->val]) {
                    ret.push_back(cur->left);
                }
                if (cur->right != nullptr && !del[cur->left->val]) {
                    ret.push_back(cur->right);
                }
            }
            dfs(cur, cur->left);
            dfs(cur, cur->right);
        } };

        if (!del[root->val]) {
            ret.push_back(root);
        }
        dfs(root, root);

        return ret;
    }
};
