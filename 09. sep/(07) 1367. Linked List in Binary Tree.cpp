#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
    bool dfs(ListNode* head, ListNode* cur, TreeNode* node) {
        if (cur == NULL) {
            return true;
        }
        if (node == NULL) {
            return false;
        }
        if (cur->val == node->val) {
            cur = cur->next;
        }
        else if (head->val == node->val) {
            head = head->next;
        }
        else {
            cur = head;
        }
        return dfs(head, cur, node->left) || dfs(head, cur, node->right);
    }
};