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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        vector<TreeNode*> nodes(n + 1);
        for (int i = 1; i <= n; i++) {
            nodes[i] = new TreeNode(i);
        }
        int pos, par;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < pre.size(); j++) {
                if (pre[j] == post[i]) {
                    pos = j;
                    pre.erase(pre.begin() + pos);
                    break;
                }
            }
            par = pre[pos - 1];
            if (!nodes[par]->left) {
                nodes[par]->left = nodes[post[i]];
            } else {
                nodes[par]->right = nodes[post[i]];
            }
        }
        return nodes[pre[0]];
    }
};