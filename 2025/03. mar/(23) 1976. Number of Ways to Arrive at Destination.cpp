#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        using pii = pair<long long, int>;
        vector<vector<pii>> paths(n);
        for (vector<int>& r : roads) {
            paths[r[0]].push_back({ r[1], r[2] });
            paths[r[1]].push_back({ r[0], r[2] });
        }
        vector<pii> mn(n, { 1e12, 0 });
        vector<vector<int>> vis(n, vector<int>(n, 0));
        mn[0] = { 0, 1 };
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({ 0, 0 });
        while (pq.size()) {
            pii t = pq.top();
            pq.pop();
            for (pii& to : paths[t.second]) {
                if (t.first + to.second > mn[to.first].first) continue;
                if (vis[t.second][to.first]) {
                    continue;
                }
                vis[t.second][to.first] = 1;
                if (t.first + to.second < mn[to.first].first) {
                    mn[to.first].first = t.first + to.second;
                    mn[to.first].second = 0;
                }
                mn[to.first].second = (mn[to.first].second + mn[t.second].second) % mod;
                pq.push({ mn[to.first].first, to.first });
            }
        }
        return mn[n - 1].second;
    }
};