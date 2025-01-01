#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j]) {
                    if (i - 1 >= 0 && land[i - 1][j]) {
                        ret[land[i - 1][j] - 1][2] = i;
                        ret[land[i - 1][j] - 1][3] = j;
                        land[i][j] = land[i - 1][j];
                        continue;
                    }
                    if (j - 1 >= 0 && land[i][j - 1]) {
                        ret[land[i][j - 1] - 1][2] = i;
                        ret[land[i][j - 1] - 1][3] = j;
                        land[i][j] = land[i][j - 1];
                        continue;
                    }
                    ret.push_back({ i, j, i, j });
                    land[i][j] = ret.size();
                }
            }
        }
        return ret;
    }
};
