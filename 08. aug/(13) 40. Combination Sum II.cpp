#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        if (accumulate(a.begin(), a.end(), 0) < target) {
            return {};
        }
        int n = a.size();
        sort(a.begin(), a.end());
        vector dp(target + 1, vector<set<vector<int>>> (n + 1));
        for (int i = 0; i <= n; i++) {
            dp[0][i].insert(vector<int>());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[j][i] = dp[j][i - 1];
                if (a[i - 1] > j) {
                    continue;
                }
                auto tmp = dp[j - a[i - 1]][i - 1];
                for (auto st : tmp) {
                    st.push_back(a[i - 1]);
                    dp[j][i].insert(st);
                }
            }
        }
        vector ret(dp[target][n].begin(), dp[target][n].end());
        return ret;
    }
};