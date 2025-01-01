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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> nums, sum;
        ListNode* node = head;
        sum.push_back(0);
        while (node) {
            nums.push_back(node->val);
            sum.push_back(sum[sum.size() - 1] + node->val);
            node = node->next;
        }
        int n = nums.size();
        unordered_map<int, int> last;
        vector<pair<int, int>> range;
        for (int i = 0; i <= n; i++) {
            if (last.find(sum[i]) != last.end()) {
                range.push_back({ last.at(sum[i]), i });
            }
            last[sum[i]] = i;
        }
        sort(range.begin(), range.end());
        vector<int> arr;
        range.push_back({ n, n + 1 });
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i < range[cur].first) {
                arr.push_back(nums[i]);
                continue;
            }
            int bound = range[cur].second;
            for (; cur < range.size() && range[cur].first < bound; cur++) {}
        }

        if (!arr.size()) {
            return 0;
        }
        ListNode* root = new ListNode;
        ListNode* prev = root;
        root->val = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            ListNode* node = new ListNode;
            node->val = arr[i];
            prev->next = node;
            prev = node;
        }
        return root;
    }
};