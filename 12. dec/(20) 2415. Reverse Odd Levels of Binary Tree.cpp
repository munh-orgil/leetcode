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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int n = 1;
        int lvl = 0;
        q.push(root);
        while (q.size()) {
            vector<int> a(n);
            vector<TreeNode*> t(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                t[i] = node;
                a[i] = node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (lvl) {
                for (int i = 0; i < n; i++) {
                    t[i]->val = a[n - i - 1];
                }
            }
            n *= 2;
            lvl ^= 1;
        }
        return root;
    }
};