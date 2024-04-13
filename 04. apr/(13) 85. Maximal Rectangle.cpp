#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> bar(m, 0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    bar[j]++;
                }
                else {
                    bar[j] = 0;
                }
            }
            for (int j = 0; j < m; j++) {
                int mnBar = 1e9;
                for (int x = j; x < m; x++) {
                    if (!matrix[i][x]) {
                        break;
                    }
                    mnBar = min(mnBar, bar[x]);
                    ret = max(ret, mnBar * (x - j + 1));
                }
            }
        }
        return ret;
    }
};