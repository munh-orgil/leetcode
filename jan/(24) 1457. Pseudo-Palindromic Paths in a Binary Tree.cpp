#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

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
    int cnt[10];
    int ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        DFS(root);
        return ans;
    }
    void DFS(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cnt[node->val]++;
        if (node->left == nullptr && node->right == nullptr) {
            int odds = 0;
            for (int i = 0; i < 10; i++) {
                if (cnt[i] % 2 == 1) {
                    odds++;
                }
            }
            if (odds <= 1) {
                ans++;
            }
        }
        DFS(node->left);
        DFS(node->right);
        cnt[node->val]--;
    }
};