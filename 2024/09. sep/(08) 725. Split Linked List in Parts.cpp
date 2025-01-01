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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k);
        if (head == NULL) {
            return ret;
        }
        vector<int> nums(1, head->val);
        while (head->next) {
            nums.push_back(head->next->val);
            head = head->next;
        }
        int n = nums.size();
        int r = n % k;
        int d = n / k;
        int cur = 0;
        for (int i = 0; i < k; i++) {
            cout << i << " " << n << " " << cur << endl;
            if (cur >= nums.size()) {
                continue;
            }
            ret[i] = new ListNode(nums[cur]);
            cur++;
            ListNode* curNode = ret[i];
            for (int j = 1; j < d + (i < r); j++) {
                curNode->next = new ListNode(nums[cur]);
                cur++;
                curNode = curNode->next;
            }
        }
        return ret;
    }
};