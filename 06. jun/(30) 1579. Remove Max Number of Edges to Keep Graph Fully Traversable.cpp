#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> dsu;
    void Init(int n) {
        dsu.resize(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dsu[0][i] = i;
            dsu[1][i] = i;
        }
    }
    int Head(int x, int type) {
        if (x == dsu[type][x]) {
            return x;
        }
        return dsu[type][x] = Head(dsu[type][x], type);
    }
    bool Union(int x, int y, int type) {
        x = Head(x, type);
        y = Head(y, type);
        if (x == y) {
            return true;
        }
        dsu[type][x] = y;
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int ret = 0;
        Init(n);
        sort(edges.rbegin(), edges.rend());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                edges[i][j]--;
            }
            if (edges[i][0] == 2) {
                ret += Union(edges[i][1], edges[i][2], 0);
                Union(edges[i][1], edges[i][2], 1);
            } else {
                ret += Union(edges[i][1], edges[i][2], edges[i][0]);
            }
        }
        int cnt;
        for (int i = 0; i < 2; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dsu[i][j] == j) {
                    cnt++;
                    if (cnt > 1) {
                        return -1;
                    }
                }
            }
        }
        return ret;
    }
};