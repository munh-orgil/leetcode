#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int d[5] = { 1, 0, -1, 0, 1 };
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ret(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    q.push({ i, j });
                    ret[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int u = x + d[i];
                int v = y + d[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= m || ret[u][v] != -1) {
                    continue;
                }
                q.push({ u, v });
                ret[u][v] = ret[x][y] + 1;
            }
        }
        return ret;
    }
};