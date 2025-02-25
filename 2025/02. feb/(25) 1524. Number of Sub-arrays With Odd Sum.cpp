#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numOfSubarrays(vector<int>& a) {
        const int mod = 1e9 + 7;
        int n = a.size();
        int o = 0, e = 1, sum = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum % 2) {
                ret = (ret + e) % mod;
                o = (o + 1) % mod;
            } else {
                ret = (ret + o) % mod;
                e = (e + 1) % mod;
            }
        }
        return ret;
    }
};