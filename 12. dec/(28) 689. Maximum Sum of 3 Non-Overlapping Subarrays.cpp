#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        int n = a.size();
        vector<vector<int>> dp(3, vector<int>(n + 1, 0)), par(3, vector<int>(n + 1, -1));
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        int id;
        for (int i = 0; i < 3; i++) {
            int mx = 0;
            for (int j = n - k; j >= 0; j--) {
                if (i) {
                    if (dp[i - 1][j + k] + pre[j + k] - pre[j] >= mx) {
                        mx = dp[i - 1][j + k] + pre[j + k] - pre[j];
                        par[i][j] = j + k;
                        if (i == 2) id = j;
                    } else {
                        mx = max(mx, dp[i - 1][j]);
                        par[i][j] = par[i][j + 1];
                    }
                } else {
                    mx = max(mx, pre[j + k] - pre[j]);
                }
                dp[i][j] = mx;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cout << par[i][j] << " ";
            }
            cout << endl;
        }
        vector<int> ret;
        for (int i = 2; i > 0; i--) {
            ret.push_back(id);
            id = par[i][id];
        }
        ret.push_back(id);
        return ret;
    }
};