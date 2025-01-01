#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimizedMaximum(int n, vector<int>& a) {
        int l = 1;
        int r = *max_element(a.begin(), a.end());
        int ret = r;
        while (l <= r) {
            int m = (l + r) / 2;
            int cur = 0;
            for (int i : a) {
                cur += (i + m - 1) / m;
            }
            if (cur > n) {
                l = m + 1;
            } else {
                ret = min(ret, m);
                r = m - 1;
            }
        }
        return ret;
    }
};