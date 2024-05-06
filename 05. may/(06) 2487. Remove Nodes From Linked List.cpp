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
    ListNode* removeNodes(ListNode* head) {
        auto node = head;
        stack<ListNode*> st;
        while (node != NULL) {
            while (!st.empty() && st.top()->val < node->val) {
                st.pop();
            }
            st.push(node);
            node = node->next;
        }
        cout << st.top()->val << endl;
        auto ret = new ListNode(st.top()->val);
        st.pop();
        while (!st.empty()) {
            ret = new ListNode(st.top()->val, ret);
            st.pop();
        }
        return ret;
    }
};