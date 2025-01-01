#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    const int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < high; i++) {
            if (i + zero <= high) dp[i + zero] = (dp[i + zero] + dp[i]) % mod;
            if (i + one <= high) dp[i + one] = (dp[i + one] + dp[i]) % mod;
        }
        int ret = 0;
        for (int i = low; i <= high; i++) {
            ret = (ret + dp[i]) % mod;
        }
        return ret;
    }
};