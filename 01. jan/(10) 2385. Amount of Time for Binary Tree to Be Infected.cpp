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
    unordered_map<int, vector < int >> path;
    int ans = 0;
    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        makePath(root);
        DFS(start, start, 0);
        return ans;
    }

    void makePath(TreeNode* node) {
        if (node->left != NULL) {
            path[node->val].push_back(node->left->val);
            path[node->left->val].push_back(node->val);
            makePath(node->left);
        }
        if (node->right != NULL) {
            path[node->val].push_back(node->right->val);
            path[node->right->val].push_back(node->val);
            makePath(node->right);
        }
    }

    void DFS(int cur, int parent, int dist) {
        ans = max(ans, dist);
        for (int to : path[cur]) {
            if (to != parent) {
                DFS(to, cur, dist + 1);
            }
        }
    }
};