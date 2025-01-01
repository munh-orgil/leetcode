#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector path(n, vector<pair<double, int>> ());
        int m = edges.size();
        int u, v;
        for (int i = 0; i < m; i++) {
            u = edges[i][0];
            v = edges[i][1];
            path[u].push_back({ succProb[i], v });
            path[v].push_back({ succProb[i], u });
        }
        priority_queue<pair<double, int>> pq;
        vector<double> mx(n, 0);

        mx[start_node] = 1;
        pq.push({ 1, start_node });
        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();
            for (auto [c, to] : path[node]) {
                if (mx[to] < cost * c) {
                    mx[to] = cost * c;
                    pq.push({ cost * c, to });
                }
            }
        }
        return mx[end_node];
    }
};