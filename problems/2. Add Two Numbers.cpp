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
        int sum;
        ListNode *ans = new ListNode;
        while (l1 != NULL || l2 != NULL) {
            int val1 = 0, val2 = 0;
            if (l1 != NULL) {
                val1 = l1->val;
            }
            if (l2 != NULL) {
                val2 = l2->val;
            }
            sum = val1 + val2;
            ans->val = sum;
            ans->next = new ListNode;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution{};
    int n, m;
    cin >> n >> m;
    vector<int> greeds(n), cookies(m);
    for (int i = 0; i < n; i++) {
        cin >> greeds[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> cookies[i];
    }
    ListNode *res = addTwoNumbers()
}