#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        int n = d.size();
        vector<int> dp(400);
        dp[0] = 0;
        int pt = 0;
        for (int i = 1; i < 400; i++) {
            if (pt < n && i == d[pt]) {
                dp[i] = min({ dp[i - 1] + c[0], dp[max(i - 7, 0)] + c[1], dp[max(i - 30, 0)] + c[2] });
                pt++;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[399];
    }
};