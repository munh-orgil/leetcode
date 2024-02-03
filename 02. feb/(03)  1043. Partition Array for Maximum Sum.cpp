#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int mx = 0;
            for (int j = 1; j <= min(k, i); j++) {
                mx = max(mx, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + mx * j);
            }
        }
        return dp[n];
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    auto sol = Solution{};
    auto res = sol.maxSumAfterPartitioning(a, k);
    cout << res << endl;
}