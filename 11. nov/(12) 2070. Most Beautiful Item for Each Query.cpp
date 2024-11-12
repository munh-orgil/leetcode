#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> maximumBeauty(vector<vector<int>>& a, vector<int>& queries) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> b, c;
        b.push_back(a[0][0]);
        c.push_back(a[0][1]);
        for (int i = 1; i < n; i++) {
            if (a[i][0] != b.back()) {
                b.push_back(a[i][0]);
                c.push_back(a[i][1]);
            } else {
                c.back() = max(c.back(), a[i][1]);
            }
        }
        n = b.size();
        vector<int> mx(n + 1, 0), ret;
        for (int i = 0; i < n; i++) {
            mx[i + 1] = max(mx[i], c[i]);
        }
        for (int q : queries) {
            int idx = lower_bound(b.begin(), b.end(), q) - b.begin();
            while (idx >= n || (idx >= 0 && b[idx] > q)) {
                idx--;
            }
            if (idx < 0) {
                ret.push_back(0);
                continue;
            }
            ret.push_back(mx[idx + 1]);
        }
        return ret;
    }
};