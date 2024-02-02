#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()

class Solution {
public:
    int findPaths(int n, int m, int mx, int stRow, int stCol) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0)), tmp(n + 2, vector<int>(m + 2, 0));
        dp[stRow + 1][stCol + 1] = 1;
        int res = 0;
        while (mx--) {
            tmp.resize(n + 2, vector<int>(m + 2, 0));

            for (int i = 1; i <= n; i++) {
                res = (res + dp[i][1]) % MOD;
                res = (res + dp[i][m]) % MOD;
                dp[i][0] = 0;
                dp[i][m + 1] = 0;
            }
            for (int i = 1; i <= m; i++) {
                res = (res + dp[1][i]) % MOD;
                res = (res + dp[n][i]) % MOD;
                dp[0][i] = 0;
                dp[n + 1][i] = 0;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    tmp[i][j] = ((dp[i - 1][j] + dp[i + 1][j]) % MOD + (dp[i][j - 1] + dp[i][j + 1]) % MOD) % MOD;
                }
            }
            dp = tmp;
        }
        return res;
    }
};

int main() {
    int n, m, mx, stRow, stCol;
    cin >> n >> m >> mx >> stRow >> stCol;
    Solution sol = Solution{};
    auto res = sol.findPaths(n, m, mx, stRow, stCol);
    debug(res);
}