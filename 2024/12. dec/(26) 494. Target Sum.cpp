#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        vector<unordered_map<int, int>> dp(n);
        function<int(int, int)> rec;
        rec = [&](int idx, int sum) -> int {
            if (idx == n) {
                return sum == t;
            }
            if (dp[idx].find(sum) != dp[idx].end()) {
                return dp[idx][sum];
            }
            return dp[idx][sum] = rec(idx + 1, sum + a[idx]) + rec(idx + 1, sum - a[idx]);
            };
        return rec(0, 0);
    }
};