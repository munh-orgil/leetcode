#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximumCandies(vector<int>& c, long long k) {
        int l = 1, r = *max_element(c.begin(), c.end());
        int m, cnt, ret = 0;
        while (l <= r) {
            m = (l + r) / 2;
            cnt = 0;
            for (int i : c) {
                cnt += i / m;
            }
            if (cnt >= k) {
                ret = max(ret, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ret;
    }
};