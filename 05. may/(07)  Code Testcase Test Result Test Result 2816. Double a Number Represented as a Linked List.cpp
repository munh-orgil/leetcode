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
    ListNode* doubleIt(ListNode* head) {
        auto ret = new ListNode((head->val * 2) / 10);
        auto ln = ret;
        if (ln->val) {
            ln->next = new ListNode;
            ln = ln->next;
        }
        while (head != NULL) {
            ln->val = head->val * 2;
            if (head->next != NULL) {
                ln->val += (head->next->val * 2) / 10;
            }
            ln->val %= 10;
            head = head->next;
            if (head != NULL) {
                ln->next = new ListNode;
                ln = ln->next;
            }
        }
        return ret;
    }
};