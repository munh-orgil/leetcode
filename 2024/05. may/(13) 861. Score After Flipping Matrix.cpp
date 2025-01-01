#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (!grid[i][0]) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int sum;
        for (int i = 0; i < m; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[j][i];
            }
            if (sum < n - sum) {
                for (int j = 0; j < n; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[i][j] << (m - 1 - j);
            }
            ret += sum;
        }
        return ret;
    }
};