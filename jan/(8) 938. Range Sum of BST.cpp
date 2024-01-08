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
    int low;
    int high;
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        DFS(root);
        return ans;
    }

    void DFS(TreeNode* node) {
        if (node->val >= low && node->val <= high) {
            ans += node->val;
        }
        if (node->left != NULL) {
            DFS(node->left);
        }
        if (node->right != NULL) {
            DFS(node->right);
        }
    }
};