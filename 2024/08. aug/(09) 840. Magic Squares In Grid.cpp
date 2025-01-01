#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ret = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                vector<bool> incl(10, 0);
                bool ok = 1;
                for (int i1 = i; i1 < i + 3; i1++) {
                    int sum = 0;
                    for (int j1 = j; j1 < j + 3; j1++) {
                        if (grid[i1][j1] > 9 || !grid[i1][j1] || incl[grid[i1][j1]]) {
                            ok = 0;
                            break;
                        }
                        incl[grid[i1][j1]] = 1;
                        sum += grid[i1][j1];
                    }
                    ok = ok & (sum == 15);
                    if (!ok) break;
                }
                for (int j1 = j; j1 < j + 3; j1++) {
                    int sum = 0;
                    for (int i1 = i; i1 < i + 3; i1++) {
                        sum += grid[i1][j1];
                    }
                    ok = ok & (sum == 15);
                    if (!ok) break;
                }
                ok = ok & (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15);
                ok = ok & (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == 15);
                if (ok) {
                    ret++;
                }
            }
        }
        return ret;
    }
};