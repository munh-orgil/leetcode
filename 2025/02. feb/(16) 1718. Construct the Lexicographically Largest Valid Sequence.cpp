#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ret(2 * n - 1, 0);
        vector<bool> used(n + 1, 0);
        function<void(int)> rec;
        bool ok = 0;
        rec = [&](int idx) {
            if (idx == 2 * n - 1) {
                ok = 1;
                return;
            }
            if (ret[idx]) {
                rec(idx + 1);
                return;
            }
            for (int i = n; i >= 1; i--) {
                if (used[i]) continue;
                if (i == 1) {
                    ret[idx] = i;
                } else {
                    if (idx + i >= 2 * n - 1 || ret[idx + i]) continue;
                    ret[idx] = ret[idx + i] = i;
                }
                used[i] = 1;
                rec(idx + 1);
                if (ok) {
                    return;
                }
                if (i == 1) ret[idx] = 0;
                else ret[idx] = ret[idx + i] = 0;
                used[i] = 0;
            }
            };
        rec(0);
        return ret;
    }
};