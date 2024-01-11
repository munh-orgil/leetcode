#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        DFS(root, root->val, root->val);
        return ans;
    }
    void DFS(TreeNode* node, int mn, int mx) {
        if (node == nullptr) {
            return;
        }
        ans = max(ans, max(node->val - mn, mx - node->val));
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        DFS(node->left, mn, mx);
        DFS(node->right, mn, mx);
        return;
    }
};