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
    TreeNode* recoverFromPreorder(string s) {
        int idx = 0, level = 0;
        TreeNode* node = new TreeNode(-1);
        function<void(TreeNode*, int)> rec;
        rec = [&](TreeNode* parent, int lvl) {
            while (idx < s.length() && lvl == level) {
                int num = 0;
                while (idx < s.length() && isdigit(s[idx])) {
                    num = num * 10 + (s[idx++] - '0');
                }
                TreeNode* node = new TreeNode(num);
                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
                level = 0;
                while (idx < s.length() && s[idx] == '-') {
                    level++;
                    idx++;
                }
                rec(node, lvl + 1);
            }
            };
        rec(node, 0);
        return node->left;
    }
};