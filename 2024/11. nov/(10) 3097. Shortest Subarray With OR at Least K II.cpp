#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int convert(vector<int>& a) {
        int ret = 0;
        for (int i = 0; i < 30; i++) {
            ret += (a[i] > 0) << i;
        }
        return ret;
    }
    int minimumSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        vector<int> cnt(30, 0);
        int ret = 1e9;
        int l = 0;
        for (int i = 0; i < n; i++) {
            bool ok = 1;
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    cnt[j]++;
                }
            }
            ok = (convert(cnt) >= k);
            while (ok && l <= i) {
                for (int j = 0; j < 30; j++) {
                    if (a[l] & (1 << j)) {
                        cnt[j]--;
                    }
                }
                ok = (convert(cnt) >= k);
                ret = min(ret, i - l + 1);
                l++;
            }
        }
        return (ret == 1e9 ? -1 : ret);
    }
};