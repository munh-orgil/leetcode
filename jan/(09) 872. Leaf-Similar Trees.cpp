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
    vector < int > leaves1, leaves2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        DFS(root1, 1);
        DFS(root2, 2);
        if (leaves1.size() != leaves2.size()) {
            return false;
        }
        int n = leaves1.size();
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) {
                return false;
            }
        }
        return true;
    }
    void DFS(TreeNode* node, int type) {
        if (node->left == NULL && node->right == NULL) {
            if (type == 1) {
                leaves1.push_back(node->val);
            }
            else {
                leaves2.push_back(node->val);
            }
            return;
        }
        if (node->left != NULL) {
            DFS(node->left, type);
        }
        if (node->right != NULL) {
            DFS(node->right, type);
        }
    }
};