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
    int sumOfLeftLeaves(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int ret = sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
        if (node->left != NULL) {
            if (node->left->left == NULL && node->left->right == NULL) {
                ret += node->left->val;
            }
        }
        return ret;
    }
};