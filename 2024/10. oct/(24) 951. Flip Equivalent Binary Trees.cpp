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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!cmp(root1, root2)) {
            return false;
        }
        if (!flipEquiv(root1->left, root2->left) && !flipEquiv(root1->right, root2->right)) {
            return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        }
        return true;
    }
    bool cmp(TreeNode* x, TreeNode* y) {
        if (!x & !y) {
            return true;
        }
        if (!x || !y) {
            return false;
        }
        return x->val == y->val;
    }
};