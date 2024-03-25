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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        for (; head != NULL; head = head->next) {
            nodes.push_back(head);
        }
        int n = nodes.size();
        if (n == 1) {
            return;
        }
        for (int i = 0; i < n / 2; i++) {
            nodes[n - i - 1]->next = nodes[i]->next;
            nodes[i]->next = nodes[n - i - 1];
        }
        if (n % 2) {
            nodes[n / 2]->next = nodes[n / 2 + 1];
        }
        nodes[n / 2]->next = NULL;
    }
};