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
    int findTheWinner(int n, int k) {
        ListNode* head = new(ListNode);
        auto cur = head;
        for (int i = 1; i < n; i++) {
            cur->val = i;
            cur->next = new(ListNode);
            cur = cur->next;
        }
        cur->val = n;
        cur->next = head;

        auto prev = cur;
        cur = head;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < k - 1; j++) {
                cur = cur->next;
                prev = prev->next;
            }
            prev->next = prev->next->next;
            cur = cur->next;
        }
        return cur->val;
    }
};