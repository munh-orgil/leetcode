#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;
#define _ << " " << 
#define ll long long
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()

class Solution {
public:
    Solution() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n + 1, 0);
        for (auto t : trust) {
            cnt[t[0]] = -1;
            if (cnt[t[1]] == -1) {
                continue;
            }
            cnt[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int> (2));
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    Solution sol = Solution{};
    auto res = sol.findJudge(n, a);
    cout << res << endl;
}