#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

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
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int cnt;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        cnt = n;
        dfs(head);
        return head;
    }
    void dfs(ListNode* cur) {
        if (cur == NULL) {
            return;
        }
        dfs(cur->next);
        cnt--;
        if (cnt == 0) {
            cur = cur->next;
        }
    }
};