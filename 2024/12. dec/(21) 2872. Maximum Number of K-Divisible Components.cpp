#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& adj, vector<int>& a, int k) {
        using ll = long long;
        vector<vector<int>> paths(n);
        for (vector<int>& v : adj) {
            paths[v[0]].push_back(v[1]);
            paths[v[1]].push_back(v[0]);
        }
        int ret = 1;
        function<ll(int, int)>dfs = [&](int cur, int par) -> ll {
            ll sum = a[cur];
            for (int to : paths[cur]) {
                if (to == par) continue;
                ll x = dfs(to, cur);
                if (x % k == 0) ret++;
                else sum += x;
            }
            return sum;
            };

        dfs(0, 0);
        return ret;
    }
};