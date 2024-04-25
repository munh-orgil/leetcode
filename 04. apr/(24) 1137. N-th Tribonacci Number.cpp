#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(1);
        for (int i = 3; i <= 37; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
        }
    }
    int tribonacci(int n) {
        return dp[n];
    }
};
