#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        const vector moveX = { 1, 0, 0, -1 };
        const vector moveY = { 0, 1, -1, 0 };

        vector vis(n, vector(m, false));
        function<void(int, int, vector<pair<int, int>>&)>dfs;
        dfs = [&](int x, int y, vector<pair<int, int>>& arr) {
            arr.push_back({ x, y });
            vis[x][y] = 1;
            int u, v;
            for (int i = 0; i < 4; i++) {
                u = x + moveX[i];
                v = y + moveY[i];
                if (u >= n || u < 0 || v >= m || v < 0 || !grid2[u][v] || vis[u][v]) {
                    continue;
                }
                dfs(u, v, arr);
            }
            };

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j]) {
                    vector<pair<int, int>> arr;
                    dfs(i, j, arr);
                    int add = 1;
                    for (auto [x, y] : arr) {
                        if (!grid1[x][y]) {
                            add = 0;
                            break;
                        }
                    }
                    ret += add;
                }
            }
        }
        return ret;
    }
};