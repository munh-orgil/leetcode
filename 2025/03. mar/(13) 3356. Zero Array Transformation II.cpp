#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        int q = queries.size();
        int l = 0;
        int r = q;
        int ret = 1e9;
        while (l <= r) {
            vector<int> x(n + 1, 0);
            int m = (l + r) / 2;
            for (int i = 0; i < m; i++) {
                x[queries[i][0]] += queries[i][2];
                x[queries[i][1] + 1] -= queries[i][2];
            }
            int sum = 0;
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                sum += x[i];
                if (sum < a[i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ret = min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (ret == 1e9) {
            ret = -1;
        }
        return ret;
    }
};