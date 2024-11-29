#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumTime(vector<vector<int>>& a) {
        using PII = pair<int, int>;
        int n = a.size();
        int m = a[0].size();
        if (a[0][1] > 1 && a[1][0] > 1) {
            return -1;
        }
        int dir[5] = { 1, 0, -1, 0, 1 };
        vector<vector<int>> cnt(n, vector<int>(m, 1e9));
        cnt[0][0] = 0;
        queue<PII> q;
        q.push({ 0, 0 });
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int u = x + dir[i];
                int v = y + dir[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= m) continue;
                if (a[u][v] <= cnt[x][y] + 1) {
                    if (cnt[u][v] > cnt[x][y] + 1) {
                        cnt[u][v] = cnt[x][y] + 1;
                        q.push({ u, v });
                    }
                } else {
                    if (cnt[u][v] > a[u][v] + (a[u][v] - cnt[x][y] + 1) % 2) {
                        cnt[u][v] = a[u][v] + (a[u][v] - cnt[x][y] + 1) % 2;
                        q.push({ u, v });
                    }
                }
            }
        }
        return cnt[n - 1][m - 1];
    }
};
