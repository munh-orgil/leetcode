#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> p(n), v(n, 1), e(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        function<int(int)> find;
        find = [&](int x) {
            if (x == p[x]) {
                return x;
            }
            return p[x] = find(p[x]);
            };
        auto join = [&](int x, int y) {
            x = find(x);
            y = find(y);
            e[x]++;
            if (x == y) {
                return;
            }
            p[y] = x;
            v[x] += v[y];
            e[x] += e[y];
            };
        for (vector<int>& edge : edges) {
            join(edge[0], edge[1]);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += (p[i] == i && (v[i] * (v[i] - 1) / 2 == e[i]));
        }
        return ret;
    }
};