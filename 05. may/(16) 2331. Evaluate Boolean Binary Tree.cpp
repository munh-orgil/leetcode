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
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    bool evaluateTree(TreeNode* root) {
        if (root == NULL) {
            return 1;
        }
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) | evaluateTree(root->right);
        }
        else {
            return evaluateTree(root->left) & evaluateTree(root->right);
        }
    }
};