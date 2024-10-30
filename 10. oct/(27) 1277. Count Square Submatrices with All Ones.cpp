#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector sum(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
            }
        }
        int ret = 0;
        for (int l = 1; l <= min(n, m); l++) {
            for (int i = l - 1; i < n; i++) {
                for (int j = l - 1; j < m; j++) {
                    if (sum[i + 1][j + 1] - sum[i - l + 1][j + 1] - sum[i + 1][j - l + 1] + sum[i - l + 1][j - l + 1] == l * l) {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};