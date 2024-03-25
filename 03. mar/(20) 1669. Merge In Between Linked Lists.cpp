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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int pt1 = 0;
        ListNode* head = list1;
        for (; pt1 < a - 1; pt1++, list1 = list1->next);
        ListNode* tmp = list1;
        for (; pt1 <= b; pt1++, tmp = tmp->next);
        list1->next = list2;
        for (; list2->next != NULL; list2 = list2->next);
        list2->next = tmp;
        return head;
    }
};