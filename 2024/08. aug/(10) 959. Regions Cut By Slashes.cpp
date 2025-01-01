#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> sides;
    vector<int> par;
    int head(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = head(par[x]);
    }
    void join(int x, int y) {
        x = head(x);
        y = head(y);
        if (x != y) {
            par[x] = y;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        sides = vector (n * (n + 1) * 2, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                sides[i * (n + 1) + j] = i * (n + 1) + j;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                sides[n * (n + 1) + j * (n + 1) + i] = n * (n + 1) + j * (n + 1) + i;
            }
        }
        par = vector<int> (n * (n + 1) * 2, 0);
        for (int i = 0; i < n * (n + 1) * 2; i++) {
            par[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int l = i * (n + 1) + j;
                int r = l + 1;
                int u = n * (n + 1) + j * (n + 1) + i;
                int d = u + 1;
                if (grid[i][j] == '\\') {
                    join(sides[u], sides[r]);
                    join(sides[l], sides[d]);
                    continue;
                }
                if (grid[i][j] == '/') {
                    join(sides[u], sides[l]);
                    join(sides[r], sides[d]);
                    continue;
                }
                join(sides[u], sides[l]);
                join(sides[l], sides[d]);
                join(sides[d], sides[r]);
            }
        }
        vector<bool> incl(n * (n + 1) * 2, 0);
        int ret = 0;

        for (int i = 0; i < n * (n + 1) * 2; i++) {
            int x = head(i);
            if (!incl[x]) {
                ret++;
                incl[x] = 1;
            }
        }
        return ret;
    }
};