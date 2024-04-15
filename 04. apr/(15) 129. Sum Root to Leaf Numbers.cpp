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
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* node, int num) {
        if (node->left == NULL && node->right == NULL) {
            ans += num;
            return;
        }
        num = num * 10 + node->val;
        dfs(node->left, num);
        dfs(node->right, num);
    }
};