#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countUnguarded(int n, int m, const vector<vector<int>>& g, const vector<vector<int>>& w) {
        vector<vector<int>> vis(n, vector<int> (m, 1));
        for (auto& v : w) {
            vis[v[0]][v[1]] = 2;
        }
        for (auto& v : g) {
            vis[v[0]][v[1]] = 2;
        }
        int moveX[4] = { 1, 0, -1, 0 };
        int moveY[4] = { 0, 1, 0, -1 };
        for (auto& v : g) {
            for (int i = 0; i < 4; i++) {
                int x = v[0] + moveX[i];
                int y = v[1] + moveY[i];
                while (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] != 2) {
                    vis[x][y] = 0;
                    x += moveX[i];
                    y += moveY[i];
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret += (vis[i][j] == 1);
            }
        }
        return ret;
    }
};