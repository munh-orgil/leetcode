#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    bool hasCycle(ListNode *head) {
        ListNode *n1, *n2;
        n1 = head;
        n2 = head;
        while (n1 && n2 && n2->next) {
            n1 = n1->next;
            n2 = n2->next->next;
            if (n1 == n2) {
                return true;
            }
        }
        return false;
    }
};