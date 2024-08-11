#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
        }
        if (sum <= 1) {
            return sum;
        }
        const vector<int> moveX = { 1, 0, 0, -1 };
        const vector<int> moveY = { 0, 1, -1, 0 };
        function<void(int, int, int)> dfs;
        vector a(n, vector<int> (m, 0));
        dfs = [&](int x, int y, int color) {
            a[x][y] = color;
            int u, v;
            for (int k = 0; k < 4; k++) {
                u = x + moveX[k];
                v = y + moveY[k];
                if (u < n && u >= 0 && v < m && v >= 0 && a[u][v] == 0 && grid[u][v]) {
                    dfs(u, v, color);
                }
            }
            };
        function<int()> cnt;
        cnt = [&]() {
            int ret = 0;
            a = vector<vector<int>> (n, vector<int> (m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!a[i][j] && grid[i][j]) {
                        ret++;
                        dfs(i, j, ret);
                    }
                }
            }
            return ret;
            };

        if (cnt() > 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    if (cnt() > 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};