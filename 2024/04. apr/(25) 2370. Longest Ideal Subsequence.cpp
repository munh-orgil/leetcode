#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26, 0);
        dp[s[0] - 'a'] = 1;
        int ret = 0;
        for (int i = 1; i < n; i++) {
            int x = s[i] - 'a';
            int mx = 0;
            for (int j = max(0, x - k); j <= min(25, x + k); j++) {
                mx = max(mx, dp[j]);
            }
            dp[x] = mx + 1;
            ret = max(ret, mx);
        }
        return ret + 1;
    }
};
