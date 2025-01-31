#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int largestIsland(vector<vector<int>>& a) {
        int n = a.size();
        function<void(int, int, int)> dfs;
        vector<vector<int>> color(n, vector<int>(n, 0));
        vector<int> d = { 1, 0, -1, 0, 1 };
        dfs = [&](int x, int y, int c) {
            color[x][y] = c;
            for (int i = 0; i < 4; i++) {
                int u = x + d[i];
                int v = y + d[i + 1];
                if (u < 0 || v < 0 || u >= n || v >= n || !a[u][v] || color[u][v]) {
                    continue;
                }
                dfs(u, v, c);
            }
            };

        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] && !color[i][j]) {
                    m++;
                    dfs(i, j, m);
                }
            }
        }
        vector<int> cnt(m + 1, 0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (color[i][j]) {
                    ret = max(ret, ++cnt[color[i][j]]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!a[i][j]) {
                    set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int u = i + d[k];
                        int v = j + d[k + 1];
                        if (u < 0 || v < 0 || u >= n || v >= n || !color[u][v]) {
                            continue;
                        }
                        st.insert(color[u][v]);
                    }
                    int sum = 1;
                    for (int k : st) {
                        sum += cnt[k];
                    }
                    ret = max(ret, sum);
                }
            }
        }
        return ret;
    }
};