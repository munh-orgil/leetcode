#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumSize(vector<int>& a, int m) {
        int n = a.size();
        int l = 1;
        int r = *max_element(a.begin(), a.end());
        int ret = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += ((a[i] + mid - 1) / mid) - 1;
            }
            if (cnt <= m) {
                ret = min(ret, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }
};