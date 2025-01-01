#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    using ll = long long;
    ll maximumSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        int m = *max_element(a.begin(), a.end());
        vector<bool> incl(m + 1, 0);
        int sz = 0;
        int l = 0;
        ll sum = 0;
        ll ret = 0;
        auto f = [&]() {
            sum -= a[l];
            sz--;
            incl[a[l]] = 0;
            l++;
            };
        for (int i = 0; i < n; i++) {
            if (incl[a[i]]) {
                while (a[l] != a[i]) {
                    f();
                }
                f();
            }
            while (sz >= k) {
                f();
            }
            sum += a[i];
            sz++;
            incl[a[i]] = 1;
            if (sz == k) {
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};