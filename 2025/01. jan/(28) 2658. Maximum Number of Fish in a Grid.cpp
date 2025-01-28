#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMaxFish(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> d = { 1, 0, -1, 0, 1 };
        vector<vector<int>> vis(n, vector<int>(m, 0));
        function<void(int, int, int)> dfs;
        dfs = [&](int x, int y, int c) {
            vis[x][y] = c;
            for (int i = 0; i < 4; i++) {
                int u = x + d[i];
                int v = y + d[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= m || vis[u][v] || !a[u][v]) {
                    continue;
                }
                dfs(u, v, c);
            }
            };

        int color = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j]) {
                    color++;
                    dfs(i, j, color);
                }
            }
        }
        vector<int> sum(color + 1, 0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    sum[vis[i][j]] += a[i][j];
                    ret = max(ret, sum[vis[i][j]]);
                }
            }
        }
        return ret;
    }
};