#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minCapability(vector<int>& a, int k) {
        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end());
        int n = a.size(), m, cnt, ret = r;
        bool ok;
        while (l <= r) {
            m = (l + r) / 2;
            ok = 1;
            cnt = 0;
            for (int i = 0; i < n; i++) {
                if (!ok) {
                    ok = 1;
                    continue;
                }
                if (a[i] <= m) {
                    cnt++;
                    ok = 0;
                }
            }
            if (cnt >= k) {
                ret = min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};