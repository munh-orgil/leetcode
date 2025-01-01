#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<pair<int, int>>> path;
    int dijkstra(int root, int n, int threshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);
        pq.push({ 0, root });
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            for (auto to : path[t.second]) {
                int newDist = t.first + to.first;
                if (dist[to.second] > newDist && newDist <= threshold) {
                    dist[to.second] = newDist;
                    pq.push({ newDist, to.second });
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= threshold && i != root) {
                ret++;
            }
        }
        return ret;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        path = vector<vector<pair<int, int>>>(n);
        for (auto edge : edges) {
            path[edge[0]].push_back({ edge[2], edge[1] });
            path[edge[1]].push_back({ edge[2], edge[0] });
        }
        int mn = 1e9, ret;
        for (int i = 0; i < n; i++) {
            int val = dijkstra(i, n, distanceThreshold);
            if (val <= mn) {
                mn = val;
                ret = i;
            }
        }
        return ret;
    }
};