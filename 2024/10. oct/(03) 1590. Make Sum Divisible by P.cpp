#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minSubarray(vector<int>& a, int p) {
        int n = a.size();
        vector<int> pre(n + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] %= p;
            pre[i + 1] = (pre[i] + a[i]) % p;
            sum = (sum + a[i]) % p;
        }
        if (!sum) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = 0;
        int ret = n;
        for (int i = 1; i <= n; i++) {
            int x = (pre[i] - sum + p) % p;
            if (mp.find(x) != mp.end()) {
                ret = min(ret, i - mp[x]);
            }
            mp[pre[i]] = i;
        }
        if (ret == n) {
            return -1;
        }
        return ret;
    }
};