#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (vector<int>& e : edges) {
            e[0]--; e[1]--;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        function<int(int, int)> bfs = [&](int root, int group) -> int {
            queue<int> q;
            q.push(root);
            vector<int> dist(n, -1);
            dist[root] = 1;
            int ret = 1;
            while (q.size()) {
                int u = q.front();
                q.pop();
                vis[u] = group;
                for (int to : adj[u]) {
                    if (dist[to] != -1) {
                        if (abs(dist[to] - dist[u]) != 1) {
                            return -1;
                        }
                        continue;
                    }
                    dist[to] = dist[u] + 1;
                    ret = max(ret, dist[to]);
                    q.push(to);
                }
            }
            return ret;
            };
        vector<int> mx(n, 0);
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = ++x;
            }
            int val = bfs(i, vis[i]);
            if (val == -1) {
                return -1;
            }
            mx[vis[i]] = max(mx[vis[i]], val);
        }
        int ret = accumulate(mx.begin(), mx.end(), 0);
        return ret;
    }
};