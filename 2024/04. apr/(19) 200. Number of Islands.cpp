#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        function<void(int, int, int)> dfs;
        dfs = [&](int x, int y, int val) {
            const int moveX[] = { -1, 0, 1, 0 };
            const int moveY[] = { 0, -1, 0, 1 };
            vis[x][y] = val;
            for (int i = 0; i < 4; i++) {
                const int u = x + moveX[i];
                const int v = y + moveY[i];
                if (u < 0 || v < 0 || u >= n || v >= m || vis[u][v] || grid[u][v] == '0') {
                    continue;
                }
                dfs(u, v, val);
            }
            };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(i, j, ans);
                }
            }
        }
        return ans;
    }
};
