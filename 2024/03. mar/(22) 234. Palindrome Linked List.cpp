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
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        for (; head != NULL; head = head->next) {
            a.push_back(head->val);
        }
        for (int i = 0; i <= a.size() / 2; i++) {
            if (a[i] != a[a.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};