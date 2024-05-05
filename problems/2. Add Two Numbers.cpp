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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = 0;
        ListNode *ret = new ListNode;
        ListNode *ln = ret;
        while (l1 != NULL || l2 != NULL) {
            int val1 = 0, val2 = 0;
            if (l1 != NULL) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val2 = l2->val;
                l2 = l2->next;
            }
            ln->val = (val1 + val2 + r) % 10;
            r = (val1 + val2 + r) / 10;

            if (l1 != NULL || l2 != NULL) {
                ln->next = new ListNode;
                ln = ln->next;
            }
            else if (r) {
                ln->val = r;
            }
        }

        return ret;
    }
};