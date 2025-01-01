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
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode> q;
        q.push(*root);
        int n, ret = 0;
        vector<int> v, s;
        unordered_map<int, int> pos;
        while (q.size()) {
            n = q.size();
            v.clear();
            s.clear();
            for (int i = 0; i < n; i++) {
                TreeNode cur = q.front();
                q.pop();
                v.push_back(cur.val);
                s.push_back(cur.val);
                if (cur.left) q.push(*cur.left);
                if (cur.right) q.push(*cur.right);
            }
            sort(s.begin(), s.end());
            pos.clear();
            for (int i = 0; i < n; i++) {
                pos[s[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                if (pos[v[i]] != i) {
                    swap(v[i], v[pos[v[i]]]);
                    i--;
                    ret++;
                }
            }
        }
        return ret;
    }
};