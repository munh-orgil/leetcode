#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countServers(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && (r[i] >= 2 || c[j] >= 2)) {
                    ret++;
                }
            }
        }
        return ret;
    }
};