#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n), ret;
        iota(dist.begin(), dist.end(), 0);
        vector<vector<int>> paths(n);
        for (vector<int>& q : queries) {
            paths[q[1]].push_back(q[0]);
            for (int i = 1; i < n; i++) {
                for (int j : paths[i]) {
                    dist[i] = min(dist[i], dist[j] + 1);
                }
                dist[i] = min(dist[i], dist[i - 1] + 1);
            }
            ret.push_back(dist[n - 1]);
        }
        return ret;
    }
};