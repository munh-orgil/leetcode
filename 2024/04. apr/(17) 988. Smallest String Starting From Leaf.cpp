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
    string ans;
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
    void dfs(TreeNode* node, string cur) {
        if (node == NULL) {
            return;
        }
        cur += char(node->val + 'a');
        if (node->left == NULL && node->right == NULL) {
            string curCpy = cur;
            cout << node->val << endl;
            reverse(curCpy.begin(), curCpy.end());
            if (ans.empty() || curCpy < ans) {
                ans = curCpy;
            }
        }
        dfs(node->left, cur);
        dfs(node->right, cur);
    }
};