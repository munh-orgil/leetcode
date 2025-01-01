#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define ll long long

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] += matrix[i][j];
            }
        }
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            mn = min(mn, dp[n - 1][i]);
        }
        return mn;
    }
};