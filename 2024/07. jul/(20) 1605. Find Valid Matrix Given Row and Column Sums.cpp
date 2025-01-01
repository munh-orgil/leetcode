#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n = row.size();
        int m = col.size();
        vector<vector<int>> ret(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = min(row[i], col[j]);
                row[i] -= ret[i][j];
                col[j] -= ret[i][j];
            }
        }
        return ret;
    }
};