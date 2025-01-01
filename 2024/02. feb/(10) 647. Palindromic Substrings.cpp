#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j + 1] = dp[i - 1][j + 1] + isPalindrome(s, i - j, i);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[n - 1][i];
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution{};
    int res = sol.countSubstrings(s);
    cout << res << endl;
}