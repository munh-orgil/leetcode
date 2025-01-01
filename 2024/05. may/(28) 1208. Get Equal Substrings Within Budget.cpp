#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + abs(s[i] - t[i]);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int x = maxCost + pre[i];
            int idx = upper_bound(pre.begin(), pre.end(), x) - pre.begin();
            idx = min(idx, n);
            while (idx >= 0 && pre[idx] > x) {
                idx--;
            }
            ret = max(ret, idx - i);
        }
        return ret;
    }
};