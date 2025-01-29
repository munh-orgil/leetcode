#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsu(n + 1);
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
        }
        function<int(int)> find;
        find = [&](int x) {
            if (dsu[x] == x) {
                return x;
            }
            return dsu[x] = find(dsu[x]);
            };
        auto merge = [&](int x, int y) -> bool {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            dsu[x] = y;
            return true;
            };
        for (vector<int>& e : edges) {
            if (!merge(e[0], e[1])) {
                return e;
            }
        }
        return vector<int>();
    }
};