#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        map<string, int> mp;
        string s;
        for (int i = 0; i < n; i++) {
            s = "0";
            for (int j = 1; j < m; j++) {
                if (a[i][j] != a[i][0]) {
                    s += "1";
                } else {
                    s += "0";
                }
            }
            mp[s]++;
        }
        int ret = 0;
        for (auto [s, cnt] : mp) {
            ret = max(ret, cnt);
        }
        return ret;
    }
};