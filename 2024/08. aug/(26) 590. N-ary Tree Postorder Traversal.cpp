#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> postorder(Node* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    void dfs(Node* node, vector<int>& arr) {
        if (node == NULL) {
            return;
        }
        for (auto c : node->children) {
            dfs(c, arr);
        }
        arr.push_back(node->val);
    }
};