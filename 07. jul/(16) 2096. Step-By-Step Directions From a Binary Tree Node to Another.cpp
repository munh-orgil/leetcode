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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s = "";
        string t = "";
        s = path(root, startValue, s).first;
        t = path(root, destValue, t).first;
        int idx = 0;
        int n = s.size();
        int m = t.size();
        while (idx < n && idx < m && s[idx] == t[idx]) {
            idx++;
        }
        string ret = "";
        for (int i = idx; i < n; i++) {
            ret += "U";
        }
        for (int i = idx; i < m; i++) {
            ret += t[i];
        }
        return ret;
    }
    pair<string, bool> path(TreeNode* node, int dest, string& s) {
        if (node == NULL) {
            return { "", 0 };
        }
        if (node->val == dest) {
            return { s, 1 };
        }
        s += "L";
        auto p = path(node->left, dest, s);
        s.pop_back();
        if (p.second) {
            return p;
        }
        s += "R";
        p = path(node->right, dest, s);
        s.pop_back();
        if (p.second) {
            return p;
        }
        return { "", 0 };
    }
};
