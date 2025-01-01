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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a;
        while (head != NULL) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        int last = -1;
        int mn = INT_MAX, mx = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) {
                if (last == -1) {
                    last = i;
                }
                else {
                    mn = min(mn, i - last);
                    mx += i - last;
                    last = i;
                }
            }
        }
        if (mn == INT_MAX) {
            mn = mx = -1;
        }
        return { mn, mx };
    }
};