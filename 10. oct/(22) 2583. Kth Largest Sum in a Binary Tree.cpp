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
    vector<long long> sum;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        sum.clear();
        dfs(root, 0);
        if (sum.size() < k) {
            return -1;
        }
        sort(sum.rbegin(), sum.rend());
        return sum[k - 1];
    }
    void dfs(TreeNode* node, int level) {
        if (node == NULL) {
            return;
        }
        if (level == sum.size()) {
            sum.push_back(node->val);
        } else {
            sum[level] += node->val;
        }
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};