#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long gridGame(vector<vector<int>>& a) {
        int n = a[0].size();
        long long x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            x += a[0][i];
        }
        long long ret = 1e10;
        for (int i = 0; i < n; i++) {
            ret = min(ret, max(x, y));
            if (i + 1 < n) {
                x -= a[0][i + 1];
            }
            y += a[1][i];
        }
        return ret;
    }
};