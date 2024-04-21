#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> path(n + 6);
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            path[u].push_back(v);
            path[v].push_back(u);
        }
        function<void(int)> dfs;
        bool ok = 0;
        dfs = [&](int cur) {
            if (cur == destination) {
                ok = 1;
                return;
            }
            for (int i = 0; i < path[cur].size(); i++) {
                int to = path[cur][i];
                if (!vis[to]) {
                    vis[to] = 1;
                    dfs(to);
                }
            }
            };

        dfs(source);
        return ok;
    }
};
