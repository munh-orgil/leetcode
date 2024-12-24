#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int diameter(vector<vector<int>>& edge) {
        int n = edge.size() + 1;
        vector<vector<int>> adj(n);
        for (vector<int>& v : edge) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> lvl(n, 0);
        function<void(int, int)> dfs = [&](int cur, int par) {
            for (int to : adj[cur]) {
                if (to == par) continue;
                lvl[to] = lvl[cur] + 1;
                dfs(to, cur);
            }
            };

        dfs(0, 0);
        int mx = 0, id = 0;
        for (int i = 0; i < n; i++) {
            if (lvl[i] > mx) {
                mx = lvl[i];
                id = i;
            }
        }
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(id);
        dist[id] = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int to : adj[x]) {
                if (dist[to] != -1) continue;
                dist[to] = dist[x] + 1;
                q.push(to);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int d1 = diameter(e1);
        int d2 = diameter(e2);
        return max({ d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 });
    }
};