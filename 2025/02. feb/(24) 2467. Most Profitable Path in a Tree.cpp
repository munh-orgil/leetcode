#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> par(n, 0), lvl(n, 1);
        function<void(int, int)> build;
        build = [&](int c, int p) {
            par[c] = p;
            for (int to : adj[c]) {
                if (to == p) continue;
                lvl[to] = lvl[c] + 1;
                build(to, c);
            }
            };
        build(0, 0);
        int cur = bob;
        for (int i = 0; i < lvl[bob] / 2; i++) {
            amount[cur] = 0;
            cur = par[cur];
        }
        if (lvl[bob] % 2) {
            amount[cur] /= 2;
        }
        int ret = -1e9;
        function<void(int, int, int)> dfs;
        dfs = [&](int c, int p, int sum) {
            if (c && adj[c].size() == 1) {
                ret = max(ret, sum);
            }
            for (int to : adj[c]) {
                if (to == p) continue;
                dfs(to, c, sum + amount[to]);
            }
            };

        dfs(0, 0, amount[0]);
        return ret;
    }
};