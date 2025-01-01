#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    using ll = long long;
    ll maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        ll ret = 0;
        ll mn = INT_MAX;
        bool cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret += abs(a[i][j]);
                mn = min(mn, ll(abs(a[i][j])));
                if (a[i][j] <= 0) {
                    cnt ^= 1;
                }
            }
        }
        ret -= mn * cnt * 2;
        return ret;
    }
};