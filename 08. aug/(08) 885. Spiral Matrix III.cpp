#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ret;
        vector<int> pos = { rStart, cStart };
        ret.push_back(pos);
        int x = 1;
        int y = 1;
        while (ret.size() < rows * cols) {
            for (int i = 1; i <= y; i++) {
                pos[1]++;
                if (pos[0] >= 0 && pos[1] >= 0 && pos[0] < rows && pos[1] < cols) {
                    ret.push_back(pos);
                }
            }
            for (int i = 1; i <= x; i++) {
                pos[0]++;
                if (pos[0] >= 0 && pos[1] >= 0 && pos[0] < rows && pos[1] < cols) {
                    ret.push_back(pos);
                }
            }
            x++;
            y++;
            for (int i = 1; i <= y; i++) {
                pos[1]--;
                if (pos[0] >= 0 && pos[1] >= 0 && pos[0] < rows && pos[1] < cols) {
                    ret.push_back(pos);
                }
            }
            for (int i = 1; i <= x; i++) {
                pos[0]--;
                if (pos[0] >= 0 && pos[1] >= 0 && pos[0] < rows && pos[1] < cols) {
                    ret.push_back(pos);
                }
            }
            x++;
            y++;
        }
        return ret;
    }
};