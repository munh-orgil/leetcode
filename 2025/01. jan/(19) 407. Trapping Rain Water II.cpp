#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int trapRainWater(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> moveX = { 0, 0, 1, -1 };
        vector<int> moveY = { 1, -1, 0, 0 };
        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ret = 0;
        for (int i = 0; i < n; i++) {
            pq.push({ a[i][0], i, 0 });
            pq.push({ a[i][m - 1], i, m - 1 });
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
        }
        for (int i = 1; i < m - 1; i++) {
            pq.push({ a[0][i], 0, i });
            pq.push({ a[n - 1][i], n - 1, i });
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
        }
        while (pq.size()) {
            auto vec = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int u = vec[1] + moveX[i];
                int v = vec[2] + moveY[i];
                if (u < 0 || v < 0 || u >= n || v >= m || vis[u][v]) {
                    continue;
                }
                if (a[u][v] < vec[0]) {
                    ret += vec[0] - a[u][v];
                }
                vis[u][v] = 1;
                pq.push({ max(vec[0], a[u][v]), u, v });
            }
        }
        return ret;
    }
};