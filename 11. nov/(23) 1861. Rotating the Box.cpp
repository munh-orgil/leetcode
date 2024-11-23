#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> ret(m, vector<char> (n, '.'));
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j <= m; j++) {
                if (j == m || box[i][j] == '*') {
                    cnt = 0;
                    for (int k = j - 1; k >= j - cnt; k--) {
                        ret[k][n - i - 1] = '#';
                    }
                    if (j < m) ret[j][n - i - 1] = '*';
                    continue;
                }
                cnt += (box[i][j] == '#');
            }
        }
        return ret;
    }
};