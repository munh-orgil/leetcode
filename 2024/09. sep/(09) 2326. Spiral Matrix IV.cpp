#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<int> a(1, head->val);
        while (head->next) {
            a.push_back(head->next->val);
            head = head->next;
        }
        int len = a.size();
        vector moveX = { 0, 1, 0, -1 };
        vector moveY = { 1, 0, -1, 0 };
        int dir = 0;
        int x = 0, y = 0;
        int u, v;

        vector ret(n, vector<int>(m, -1));
        for (int i = 0; i < len; i++) {
            ret[x][y] = a[i];
            u = x + moveX[dir];
            v = y + moveY[dir];
            if (u < 0 || v < 0 || u >= n || v >= m || ret[u][v] != -1) {
                dir = (dir + 1) % 4;
                x = x + moveX[dir];
                y = y + moveY[dir];
            }
            else {
                x = u;
                y = v;
            }
        }
        return ret;
    }
};