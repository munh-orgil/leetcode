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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ret;
        ListNode* ln = new ListNode();
        ListNode* prev = new ListNode();
        unordered_map<int, bool> mp;
        for (auto i : nums) {
            mp[i] = 1;
        }
        ret = ln;
        while (head) {
            if (!mp[head->val]) {
                ln->val = head->val;
                ln->next = new ListNode();
                prev = ln;
                ln = ln->next;
            }
            head = head->next;
        }
        prev->next = NULL;
        return ret;
    }
};