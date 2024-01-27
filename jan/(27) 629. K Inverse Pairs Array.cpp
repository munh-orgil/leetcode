#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 5, vector<int> (k + 5, 0));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = 1;
            int lim = (i * (i - 1)) / 2;
            for (int j = 1; j < min(i, k + 1); j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
            for (int j = i; j <= min(lim, k); j++) {
                dp[i][j] = (((dp[i][j - 1] + dp[i - 1][j]) % MOD - dp[i - 1][j - i]) % MOD + MOD) % MOD;
            }
        }
        return dp[n][k];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Solution sol = Solution{};
    auto res = sol.kInversePairs(n, m);
    debug(res);
}