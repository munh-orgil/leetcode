#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        using PII = pair<int, int>;
        int n = s.size();
        vector<bool> vis(n, 0);
        vector<PII> ranges;
        for (string d : dictionary) {
            int m = d.size();
            for (int i = 0; i <= n - m; i++) {
                bool ok = 1;
                for (int j = 0; j < m; j++) {
                    if (s[i + j] != d[j]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ranges.push_back({ i, i + m - 1 });
                }
            }
        }
        sort(ranges.begin(), ranges.end(), [&](PII a, PII b) {
            return a.second < b.second;
            });

        int r = ranges.size();
        vector<int> dp(n + 1, 0);
        int mx;
        for (int i = 0; i < r; i++) {
            mx = 0;
            for (int j = 0; j < ranges[i].first; j++) {
                mx = max(mx, dp[j]);
            }
            dp[ranges[i].second] = max(dp[ranges[i].second], mx + ranges[i].second - ranges[i].first + 1);
        }
        mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dp[i]);
        }

        return n - mx;
    }
};