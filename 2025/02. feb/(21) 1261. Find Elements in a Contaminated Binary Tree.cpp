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

class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        root->val = 0;
        function<void(TreeNode*)> rec;
        st.clear();
        rec = [&](TreeNode* node) {
            st.insert(node->val);
            if (node->left) {
                node->left->val = node->val * 2 + 1;
                rec(node->left);
            }
            if (node->right) {
                node->right->val = node->val * 2 + 2;
                rec(node->right);
            }
            };
        rec(root);
    }

    bool find(int target) {
        return st.find(target) != st.end();
    }
};