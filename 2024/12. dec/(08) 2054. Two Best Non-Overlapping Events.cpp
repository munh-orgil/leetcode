#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ret = 0;
        sort(events.begin(), events.end());
        vector<int> a(n), b(n), suf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            a[i] = events[i][0];
            b[i] = events[i][1];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(suf[i + 1], events[i][2]);
        }
        int idx;
        for (int i = 0; i < n; i++) {
            idx = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            ret = max(ret, events[i][2] + suf[idx]);
        }
        return ret;
    }
};