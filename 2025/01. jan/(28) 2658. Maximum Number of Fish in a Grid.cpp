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
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        function<void(int, int, int&)> dfs;
        dfs = [&](int x, int y, int& sum) {
            vis[x][y] = 1;
            sum += a[x][y];
            for (int i = 0; i < 4; i++) {
                int u = x + d[i];
                int v = y + d[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= m || vis[u][v] || !a[u][v]) {
                    continue;
                }
                dfs(u, v, sum);
            }
            };

        int ret = 0, sum;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j]) {
                    sum = 0;
                    dfs(i, j, sum);
                    ret = max(ret, sum);
                }
            }
        }
        return ret;
    }
};