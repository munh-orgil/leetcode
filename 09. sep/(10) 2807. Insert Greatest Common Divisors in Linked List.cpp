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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto ret = head;
        while (head && head->next) {
            head->next = new ListNode(__gcd(head->val, head->next->val), head->next);
            head = head->next->next;
        }
        return ret;
    }
};