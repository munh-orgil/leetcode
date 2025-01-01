#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int moveX[] = { -1, 0, 1, 0 };
        const int moveY[] = { 0, 1, 0, -1 };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int u = i + moveY[k];
                        int v = j + moveX[k];
                        if (u < 0 || u >= n || v < 0 || v >= m || !grid[u][v]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
