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
    ListNode* mergeNodes(ListNode* head) {
        auto ret = new(ListNode);
        auto elem = ret;
        auto cur = head->next;
        int sum = 0;
        while (cur->next != NULL) {
            if (cur->val == 0) {
                elem->val = sum;
                sum = 0;
                elem->next = new(ListNode);
                elem = elem->next;
            }
            else {
                sum += cur->val;
            }
            cur = cur->next;
        }
        elem->val = sum;
        return ret;
    }
};