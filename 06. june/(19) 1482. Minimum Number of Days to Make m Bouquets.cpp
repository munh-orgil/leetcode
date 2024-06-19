#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long n = bloomDay.size();
        if (m * k > n) {
            return -1;
        }
        set<int> st(bloomDay.begin(), bloomDay.end());
        vector<int> a(st.begin(), st.end());
        int len = a.size();
        int l = 0, r = len, mid, x, y, cnt;
        int ans;
        while (l <= r) {
            mid = (l + r) / 2;
            x = a[mid];
            y = 0;
            cnt = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= x) {
                    y++;
                    if (y >= k) {
                        cnt++;
                        y = 0;
                    }
                } else {
                    y = 0;
                }
            }
            if (cnt >= m) {
                ans = x;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};