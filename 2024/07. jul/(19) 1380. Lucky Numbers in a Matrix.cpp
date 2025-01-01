#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            int col = 0;
            int mn = 1e9;
            for (int j = 0; j < m; j++) {
                if (a[i][j] < mn) {
                    mn = a[i][j];
                    col = j;
                }
            }
            int mx = 0;
            for (int j = 0; j < n; j++) {
                mx = max(mx, a[j][col]);
            }
            if (mx == a[i][col]) {
                ret.push_back(a[i][col]);
            }
        }
        return ret;
    }
};
