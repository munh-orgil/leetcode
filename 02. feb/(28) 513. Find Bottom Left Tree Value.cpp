#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

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
    int ans;
    int mx;
    int findBottomLeftValue(TreeNode* root) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        ans = root->val;
        mx = 0;
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* node, int lvl) {
        if (node == NULL) {
            return;
        }
        if (lvl > mx) {
            mx = lvl;
            ans = node->val;
        }
        dfs(node->left, lvl + 1);
        dfs(node->right, lvl + 1);
    }
};