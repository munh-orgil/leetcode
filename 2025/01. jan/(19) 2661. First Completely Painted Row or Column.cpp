#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        using PII = pair<int, int>;
        int n = mat.size();
        int m = mat[0].size();
        vector<PII> pos(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = { i, j };
            }
        }
        vector<int> row(n, m), col(m, n);
        for (int i = 0; i < n * m; i++) {
            if (!(--row[pos[arr[i]].first])) {
                return i;
            }
            if (!(--col[pos[arr[i]].second])) {
                return i;
            }
        }
        return 0;
    }
};