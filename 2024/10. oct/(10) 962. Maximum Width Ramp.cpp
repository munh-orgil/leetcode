#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxWidthRamp(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a[i] *= -1;
        }
        vector<int> mn(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            mn[i] = min(mn[i + 1], a[i]);
        }
        int ret = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < mn[i]) {
                continue;
            }
            int idx = lower_bound(mn.begin() + i, mn.end(), a[i]) - mn.begin();
            while (idx < n && mn[idx] == a[i]) {
                idx++;
            }
            ret = max(ret, idx - i);
        }
        return ret;
    }
};
